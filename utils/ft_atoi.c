/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:39:12 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/13 00:55:51 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

// static bool	ft_overflow(long long res, int neg, char *st)
// {
// 	if (neg == 0)
// 	{
// 		if ((LLONG_MAX / 10 < res) || (LLONG_MAX / 10 == res && 7 < *st - 0x30))
// 			return (1);
// 	}
// 	else
// 	{
// 		if ((LLONG_MAX + 1 / 10 < res) || (LLONG_MAX + 1 / 10 == res && 8 < *st
// 				- 0x30))
// 			return (1);
// 	}
// 	return (0);
// }

bool	ft_atoi(char *st)
{
	(void) st;
	return true;
	// int			neg;

	// while (*st == '0')
	// 	st++;
	// if (*st == '+')
	// 	st++;
	// if (*st == '-')
	// {
	// 	neg = 1;
	// 	st++;
	// }
	// while ('0' <= *st && *st <= '9')
	// {
	// 	if (ft_overflow(res, st,neg) == false)
	// 		return (NULL);
	// 	// res = res * 10 + (*st - '0');
	// 	// st++;
	// }
	// if (!('0' <= *st && *st <= '9' || *st == '\0'))
	// 	return (NULL);
	// return (res);
}
