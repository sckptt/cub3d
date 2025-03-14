/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:48:05 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:54:25 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	unsigned char	*res;

	res = ptr;
	while (size)
	{
		*res = '\0';
		res++;
		size--;
	}
}
