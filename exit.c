/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/12 17:44:01 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	c_exit(char **line)
{
	size_t	i;
    long long num;

	if (!line[CMD + 1])
		c_echo(line);
	num = ft_atoi(line[CMD + 1]);
	while (0 <= num && num <= 255)
		num = num / 256;
}
