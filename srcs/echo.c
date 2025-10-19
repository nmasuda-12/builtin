/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:43:26 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/19 14:57:56 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

static void	echo_print(char **line)
{
	int	i;

	i = CMD + 1;
	while (line[i])
	{
		printf("%s", line[i++]);
		if (line[i])
			printf(" ");
	}
}

void	c_echo(char **line)
{
	if (!line[OPT])
		printf("\n");
	else if (!ft_strncmp(line[OPT], "-n", 3))
	{
		line++;
		echo_print(line);
	}
	else
	{
		echo_print(line);
		printf("\n");
	}
}
