/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:46:10 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/12 23:40:16 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	**c_unset(char **line, char **ev)
{
	char	**new_ev;
	char	*new_line;
	int		j;

	j = 0;
	while (ev[j])
		j++;
	new_ev = malloc(sizeof(char *) * j + 1);
	if (!new_ev)
		error("unset_newev_malloc_error", NULL);
	j = 0;
	while (ev[j])
	{
		new_line = malloc(sizeof(char) * (ft_strlen(ev[j]) + 1));
		if (!new_line)
			error("unset_newline_malloc_error", new_ev);
		ft_memmove(new_line, ev[j], ft_strlen(ev[j]));
		new_ev[j] = new_line;
		j++;
	}
	new_ev[j + 1] = "\0";
	return (new_ev);
}


/*
全部移し替えるやつはできた
→複数の引数文　if文で判断するやつを作って整理する
*/