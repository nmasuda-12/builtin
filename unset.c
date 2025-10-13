/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:46:10 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/13 05:41:48 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static bool unset_arg_skip(char **line,char **ev,int j)
{
	int i;

	i = 1;
	while(line[CMD + i])
	{
		if(!(ft_strncmp(ev[j],line[CMD + i],ft_strlen(line[CMD + i]))))
			return true;
		else
		i++;
	}
	return false;
}



char	**c_unset(char **line, char **ev)
{
	char	**new_ev;
	char	*new_line;
	int		j = 0;
	int		i = 0;

	while(line[CMD + i + 1])
		i++;

	while (ev[j])
		j++;
	
	new_ev = malloc(sizeof(char *) * (j -i +1));
	if (!new_ev)
		error("unset_newev_malloc_error", NULL);
	j = 0;
	i = 0;
	while (ev[j])
	{
		if(line[CMD + 1])
		{
			if(unset_arg_skip(line,ev,j) == true)
			{
				i++;
				j++;
			}
			if(!ev[j])
				break ;
		}
		new_line = malloc(sizeof(char) * (ft_strlen(ev[j]) + 1));
		if (!new_line)
			error("unset_newline_malloc_error", new_ev);
		ft_memmove(new_line, ev[j], ft_strlen(ev[j]));
		new_ev[j-i] = new_line;
		j++;
	}
	new_ev[j -i + 1] = "\0";
	return (new_ev);
}


/*
ノーム直す
あとなんか二番目の文字がうまく消えてくれない
*/