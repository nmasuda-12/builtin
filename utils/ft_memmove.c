/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:57:53 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/12 18:05:33 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cd;
	const char	*cs;

	if (n == 0)
		return (dest);
	if (src == 0 && dest == 0)
		return (NULL);
	cd = (char *)dest;
	cs = (const char *)src;
	if (dest < src)
	{
		while (n)
			*cd++ = (n--, *cs++);
	}
	else
	{
		cd += n;
		cs += n;
		while (n)
			*--cd = (n--, *--cs);
	}
	return (dest);
}
