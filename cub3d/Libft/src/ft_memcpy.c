/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:48:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:54:49 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destin;
	const unsigned char	*sour;

	destin = dest;
	sour = src;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*destin = *sour;
		destin++;
		sour++;
		n--;
	}
	return (dest);
}
