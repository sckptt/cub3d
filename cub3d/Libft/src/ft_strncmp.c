/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:33:12 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:36 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 - *s2 == 0)
	{
		if (*s1 == '\0' && *s2 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
		if (n == 0)
			return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
