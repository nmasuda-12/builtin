/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/12 23:41:48 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	echo_exit(int num, char *mess)
{
	printf("exit\n");
	if (mess)
		printf("bash: exit: %s: numeric argument required", mess);
	exit(num);
}

void	c_exit(char **line)
{
	size_t		i;
	long long	num;

	if (!line[CMD + 1])
		echo_exit(0, NULL);
	num = ft_atoi(line[CMD + 1]);
	if (!num)
		echo_exit(2, line[CMD + 1]);
	while (!(0 <= num && num <= 255))
		num = num - 256;
	echo_exit(num, NULL);
}

/*
atoiの中身を「errorかどうかをboolでチェックして、数字に直したやつは引数に入れる」ようにする。
マイナスを対応させるようにして整理する
*/