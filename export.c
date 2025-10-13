/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/13 20:15:26 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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
		error("export_newev_malloc_error", NULL);
	j = 0;
	while (ev[j])
	{
		new_ev[j] = ev[j];
		j++;
	}
	if (i != 0)
	{
		i = 1;
		while (line[CMD + i])
		{
			new_line = ft_strdup(line[CMD + i]);
			new_ev[j + i] = new_line;
			i++;
		}
	}
	new_ev[j + i] = NULL;
	return (new_ev);
}
