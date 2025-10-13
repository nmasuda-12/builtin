/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:46:10 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/13 18:19:58 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool	unset_arg_skip(char **line, char **ev, int j)
{
	int	i;

	i = 1;
	while (line[CMD + i])
	{
		if (!(ft_strncmp(ev[j], line[CMD + i], ft_strlen(line[CMD + i]))))
			return (true);
		else
			i++;
	}
	return (false);
}



char	**c_unset(char **line, char **ev)
{
	char	**new_ev;
	char	*new_line;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (ev[j])
	{
		if (unset_arg_skip(line, ev, j) == true)
			i++;
		j++;
	}
	new_ev = malloc(sizeof(char *) * (j - i + 1));
	if (!new_ev)
		error("unset_newev_malloc_error", NULL);
	i = 0;
	j = 0;
	while (ev[j])
	{
		if (unset_arg_skip(line, ev, j) == true)
		{
			j++;
			i++;
			if (!ev[j])
				break ;
		}
		if (!ft_strncmp(ev[j], "_=", 2))
		{
			new_line = malloc(sizeof(char) * (ft_strlen("_=/usr/bin/env") + 1));
			if (!new_line)
			 	error("unset_newline_malloc_error", new_ev);
			new_line = "_=/usr/bin/env";
			new_ev[j - i] = new_line;
			printf("%s\n",new_ev[j - i]);
			j++;
			break ;
		}
		new_line = malloc(sizeof(char) * (ft_strlen(ev[j]) + 1));
		if (!new_line)
			error("unset_newline_malloc_error", new_ev);
		ft_memmove(new_line, ev[j], ft_strlen(ev[j]));
		new_ev[j - i] = new_line;
		j++;
	}
	new_ev[j -i + 1] = "\0";
	return (new_ev);
}




// char	**c_unset(char **line, char **ev)
// {
// 	char	**new_ev;
// 	char	*new_line;
// 	int		j;

// 	j = 0;
// 	while (ev[j])
// 		j++;
// 	new_ev = malloc(sizeof(char *) * (j + 1));
// 	if (!new_ev)
// 		error("unset_newev_malloc_error", NULL);
// 	j = 0;
// 	while (ev[j])
// 	{
// 		new_line = malloc(sizeof(char) * (ft_strlen(ev[j]) + 1));
// 		if (!new_line)
// 			error("unset_newline_malloc_error", new_ev);
// 		ft_memmove(new_line, ev[j], ft_strlen(ev[j]));
// 		new_ev[j] = new_line;
// 		j++;
// 	}
// 	new_ev[j + 1] = "\0";
// 	return (new_ev);
// }

/*
ノーム直す
あとなんか二番目の文字がうまく消えてくれない
*/