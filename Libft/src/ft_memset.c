/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:11:40 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:54:56 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *ptr, int n, size_t size)
{
	unsigned char	*res;

	res = ptr;
	while (size)
	{
		*res = (unsigned char)n;
		res++;
		size--;
	}
	return (ptr);
}
