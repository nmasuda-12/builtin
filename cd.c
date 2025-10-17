/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:14:57 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/17 19:18:30 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	**change_pwd(char *old_pwd, char *new_pwd, char **ev)
{
	char	**new_ev;
	int		i;

	new_ev = NULL;
	i = 0;
	while (ev[i])
		i++;
	new_ev = malloc(sizeof(char *) * i);
	new_ev[i - 1] = NULL;
	if (!new_ev)
		error();
	i = 0;
	while (new_ev[i])
	{
		if (!ft_strncmp(new_ev[i], "PWD", 3))
			new_ev[i] = ft_strdup(old_pwd);
		else if (!ft_strncmp(new_ev[i], "OLDPWD", 6))
			new_ev[i] = ft_strdup(new_pwd);
		else
			new_ev[i] = ft_strdup(ev[i]);
		if (!new_ev[i])
			error();
		i++;
	}
	return (new_ev);
}

char	**cd_c(char **line, char **ev)
{
	char	*chpath;
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = NULL;
	new_pwd = NULL;
	if (line[CMD + 2])
		error(line[0], ": cd: too many arguments", NULL, 1);
	if (line[CMD + 1] == NULL || line[CMD + 2] == '~')
		chpath = getenv("HOME");
	else
		chpath = line[CMD + 1];
	old_pwd = getpwd(NULL, 0);
	if (!old_pwd)
		error();
	if (chdir(chpath) == -1)
	{
		free(old_pwd);
		error();
	}
	new_pwd = getpwd(NULL, 0);
	if (!new_pwd)
		error();
	return (free(old_pwd), free(new_pwd), change_pwd(old_pwd, new_pwd, ev));
}
