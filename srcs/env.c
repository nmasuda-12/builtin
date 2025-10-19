/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:43:37 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/19 14:58:00 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void	c_env(char **line, char **ev)
{
	int	i;

	(void)line;
	i = 0;
	while (ev[i])
	{
		if (!ft_strncmp(ev[i], "_=", 2))
		{
			printf("_=/usr/bin/env\n");
			break ;
		}
		else
			printf("%s\n", ev[i++]);
	}
}
