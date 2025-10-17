char    **c_cd(char **line, char **ev)
{
    char    *path_to_cd;
    char    *old_pwd;
    char    *new_pwd;
    char    **new_ev;

    // 1. 引数のチェック
    if (line[CMD + 2] != NULL)
    {
        error(line[0], ": cd: too many arguments", NULL, 1);
        return (ev); // 環境変数は変更しない
    }

    // 2. 移動先パスの決定: 引数がなければホームディレクトリへ移動
    if (line[CMD + 1] == NULL || ft_strncmp(line[CMD + 1], "~", 2) == 0)
        path_to_cd = getenv("HOME");
    else
        path_to_cd = line[CMD + 1];

    if (!path_to_cd)
    {
        error(line[0], ": cd: HOME not set", NULL, 1);
        return (ev);
    }

    // 3. OLDPWD の値（現在の作業ディレクトリの絶対パス）を保存
    // getcwd(NULL, 0) は動的にメモリを割り当ててくれる
    old_pwd = getcwd(NULL, 0); 
    if (!old_pwd)
    {
        // PWDが取得できない致命的なエラー
        error(line[0], ": cd: path retrieval error", NULL, 1);
        return (ev);
    }
    
    // 4. chdir でディレクトリを移動
    if (chdir(path_to_cd) == -1)
    {
        // 移動失敗 (存在しない、権限なしなど)
        error("cd", path_to_cd, strerror(errno), 1); // errno のエラーメッセージを使用
        free(old_pwd);
        return (ev);
    }

    // 5. 移動成功: PWD の新しい値を取得
    new_pwd = getcwd(NULL, 0);
    if (!new_pwd)
    {
        // 移動はしたが、新しい PWD の取得に失敗
        error(line[0], ": cd: new path retrieval error", NULL, 1);
        free(old_pwd);
        // この場合、環境変数を更新せずに return (ev) としますが、
        // 実際には chdir が成功しているので、シェルとOSのPWDが不一致になります。
        return (ev);
    }
    
    // 6. 環境変数を更新 (OLDPWD=old_pwd, PWD=new_pwd)
    new_ev = update_pwd_env(old_pwd, new_pwd, ev);

    // 7. 割り当てたメモリを解放
    free(old_pwd);
    free(new_pwd);

    // 8. 新しい環境変数配列を返す
    // ⚠️ 呼び出し元は、返された new_ev とは異なる古い ev を free する必要があります。
    return (new_ev);
}

