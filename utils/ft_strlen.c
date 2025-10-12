/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:50:30 by nmasuda           #+#    #+#             */
/*   Updated: 2025/10/12 18:05:37 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin.h"

size_t	ft_strlen(const char *str)
{
	const char	*head;

	head = str;
	while (*str != '\0')
		str++;
	return (str - head);
}
