#include "builtin.h"

void	bild_in_check(char **line, char **ev)
{
	// char	**res;

	// res = NULL;
	if (!ft_strncmp(line[CMD], "echo", 5))
		c_echo(line);
	else if (!ft_strncmp(line[CMD], "pwd", 4))
		c_pwd(line);
	else if (!ft_strncmp(line[CMD], "env", 4))
		c_env(line, ev);
	// else if (!ft_strncmp(line[CMD], "cd", 3))
	// 	c_cd(line);
	// else if (!ft_strncmp(line[CMD], "exit", 5))
	// 	c_exit(line);
	// else if (!ft_strncmp(line[CMD], "unset", 6))
	// 	res = c_unset(line, ev);
	// else if (!ft_strncmp(line[CMD], "export", 7))
	// 	c_export(line, ev);
}

int	main(int ac, char **av, char **ev)
{
	(void)ac;
	bild_in_check(av,ev);
}
