/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:30 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/14 19:25:02 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	**change_pwd(char *line, char **ev)
{
	int		i;
	char	**new_ev;

	i = 0;
	while (ev[i])
		i++;
	new_ev = malloc(sizeof(char *) * i);
	if (!new_ev)
		return (NULL);
	i = 0;
	while (ev[i])
	{
		ev[i] = ft_strdup(new_ev[i]);
		if (!ev[i])
			return (NULL);
		if (!ft_strncmp(new_ev[i], "PWD", 3))
			new_ev[i] = line;
		i++;
	}
	return (new_ev);
}

char	**c_cd(char **line, char **ev)
{
	int	i;

	i = 0;
	if (line[CMD + 2] != NULL)
		error(line[0], ": cd: too many arguments", NULL, 1);
	if (!ft_strncmp(line[CMD + 1], "/", 2) || !ft_strncmp(line[CMD + 1], "//",
			3))
		return (change_pwd(line[CMD + 1], ev));
	// if (!line[CMD + 1])
	// {
	// 	while (line[CMD + 1])
	// 	{
	// 	}
	// }
	// printf("%s\n", getenv("PWD"));
}

/*
なぜか引数の数が合わない　引数がcmd +1つなのにtoo manyって言われる
*/