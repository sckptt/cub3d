/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:25:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:24 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = destlen;
	j = 0;
	if (size <= i)
		return (srclen + size);
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (destlen + srclen);
}
