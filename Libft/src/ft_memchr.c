/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:45:01 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:54:43 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *str, int n, size_t size)
{
	const unsigned char	*res;

	res = str;
	while (size)
	{
		if (*res == (unsigned char)n)
			return ((void *)res);
		else
		{
			size--;
			res++;
		}
	}
	return (NULL);
}
