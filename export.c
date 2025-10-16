/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/16 22:20:00 by nmasuda          ###   ########.fr       */
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

static char	**ev_add_to_new_ev(char **ev, char **new_ev)
{
	int		j;

	j = 0;
	while (ev[j])
	{
		if (!ft_strncmp(ev[j], "_=", 2))
		{
			j++;
			if (!ev[j])
			{
				j--;
				break ;
			}
		}
		new_ev[j] = ft_export_strjoin("declare -x ", ev[j]);
		if (!new_ev[j])
			error(NULL, "export_ft_strjoin_malloc_error", new_ev, 2);
		printf("j :%d , %s \n",j, new_ev[j]);
		j++;
	}
	j--;
	printf("add j :%d\n",j);
	return (new_ev);
}

static char	**arg_add_to_ev(char **line, char **new_ev, int j)
{
	int		i;
	char	*new_line;

	i = 1;
	printf("arg j:%d\n",j);
	new_line = NULL;
	while (line[CMD + i])
	{
		// printf("aaaaaaaaaaaaaaaa\n");
		new_line = ft_strdup(line[CMD + i]);
		if (!new_line)
			error(NULL, "export_ft_strfup_malloc_error", new_ev, 2);
		if (ft_strncmp(new_line, "declare -x _=", 13))
		{
			// printf("1:%s\n",new_ev[1]);
			// printf("j:%s\n",new_ev[j-1]);
			// printf("j+i-1:%s\n",new_ev[j+ i-1]);
			// printf("j+i:%s\n",new_ev[j+ i]);
			new_ev[j + i] = new_line;
		}
		// printf("j+i-1:%s\n",new_ev[j+ i-1]);
		// printf("j+i:%s\n",new_ev[j+ i]);
		// printf("j+i+1:%s\n",new_ev[j+ i+1]);
		i++;
	}
	// printf("aaaaaaaaaaaaaaaa\n");
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
	printf("firtst:%d\n",j);
	printf("firtst:%d\n",i);
	new_ev = malloc(sizeof(char *) * (j + i));
	if (!new_ev)
		error(NULL, "export_newev_malloc_error", NULL, 2);
	new_ev = ev_add_to_new_ev(ev, new_ev);
	new_ev = NULL;
	// if (i != 0)
	// 	new_ev = arg_add_to_ev(line, new_ev, j);
	// new_ev[j + i] = NULL;
	// new_ev = sort(new_ev);
	return (new_ev);
}

/*
実際envは69行あって。
exportは68行あって。
_=がないところまでは大丈夫なんだけど
evを見ていったときに数がなんか合わない
ev_add_to_new_evのところの数がおかしい、あとマロックの数をどうするのか考える
*/