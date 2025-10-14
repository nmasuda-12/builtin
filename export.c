/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/14 17:31:19 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	**chenge(char **new_ev, int i, int j)
{
	char	*tmp;

	tmp = new_ev[j];
	new_ev[j] = new_ev[i];
	new_ev[i] = tmp;
	return (new_ev);
}

static char	**sort(char **new_ev)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (new_ev[j] != NULL)
	{
		if (ft_memcmp(new_ev[i], new_ev[j]) > 0)
		{
			new_ev = chenge(new_ev, i, j);
			i = 0;
			j = i + 1;
		}
		else
			(void)(i++, j++);
	}
	return (new_ev);
}

char	**c_export(char **line, char **ev)
{
	char	**new_ev;
	char	*new_line;
	int		i;
	int		j;

	new_ev = NULL;
	new_line = NULL;
	i = 0;
	j = 0;
	while (line[CMD + i])
		i++;
	while (ev[j])
		j++;
	new_ev = malloc(sizeof(char *) * (j + i + 1));
	if (!new_ev)
		error(NULL,"export_newev_malloc_error", NULL,2);
	j = 0;
	// while (ev[j])
	// {
	// 	if (!ft_strncmp(ev[j], "_=", 2))
	// 	{
	// 		j++;
	// 		if (!ev[j])
	// 			break ;
	// 	}
	// 	new_ev[j] = ft_strjoin("declare -x ", ev[j]);
	// 	if (!new_ev[j])
	// 		error(NULL,"export_ft_strjoin_malloc_error", new_ev,2);
	// 	j++;
	// }→ココを一つの関数にする

	// if (i != 0)
	// {
	// 	i = 1;
	// 	while (line[CMD + i])
	// 	{
	// 		new_line = ft_strdup(line[CMD + i]);
	// 		if (!new_line)
	// 			error(NULL,"export_ft_strfup_malloc_error", new_ev,2);
	// 		if (ft_strncmp(new_line, "declare -x _=", 13))
	// 			new_ev[j + i] = new_line;
	// 		i++;
	// 	}
	// }→ココを一つの関数にする２

	new_ev[j + i] = NULL;
	new_ev = sort(new_ev);
	return (new_ev);
}

/*
normなおす
*/