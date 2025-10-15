/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:30 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/15 18:53:50 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	**change_pwd(char *line, char **ev)
{
	int		i;
	char	**new_ev;

	new_ev = NULL;
	i = 0;
	while (ev[i])
		i++;
	new_ev = malloc(sizeof(char *) * i);
	if (!new_ev)
		return (NULL);
	i = 0;
	while (ev[i])
	{
		new_ev[i] = ft_strdup(ev[i]);
		if (!new_ev[i])
			return (NULL);
		if (!ft_strncmp(new_ev[i], "PWD", 3))
			new_ev[i] = ft_strjoin("PWD=", line);
		i++;
	}
	new_ev[i] = NULL;
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
	return (NULL);
}
