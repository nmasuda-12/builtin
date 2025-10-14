/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/14 19:11:11 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	echo_exit(char **line,int num, char *mess)
{
	printf("exit\n");
	if (mess)
		printf("%s: exit: %s: numeric argument required",line[CMD + 1], mess);
	exit(num);
}

void	c_exit(char **line)
{
	size_t		i;
	long long	num;

	if (line[CMD + 2])
	{
		printf("%s: exit: too many arguments",line[0]);
		echo_exit(line,1, NULL);
	}
	if (!line[CMD + 1])
		echo_exit(NULL,0, NULL);
	// num = ft_atoi(line[CMD + 1]);
	if (!num)
		echo_exit(line,2, line[CMD + 1]);
	while (!(0 <= num && num <= 255))
		num = num - 256;
	echo_exit(line,num, NULL);
}

/*
atoiの中身を「errorかどうかをboolでチェックして、数字に直したやつは引数に入れる」ようにする。
マイナスを対応させるようにして整理する

nmasuda@c5r1s6:~$ exit 1 2 3
exit
bash: exit: too many arguments

を作る

*/