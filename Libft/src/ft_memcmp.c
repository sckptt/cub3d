/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:47 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:54:45 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned const char	*one;
	unsigned const char	*two;

	one = str1;
	two = str2;
	if (n == 0)
		return (0);
	while (n-- > 0)
	{
		if (*one != *two)
			return (*one - *two);
		one++;
		two++;
	}
	return (0);
}
