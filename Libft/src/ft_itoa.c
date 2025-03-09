/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:01:18 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:54:41 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	check_length(int n)
{
	int	length;

	length = 0;
	if (n <= 0)
		length = 1;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		length;
	int		num;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = check_length(n);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	num = n;
	neg = n < 0;
	if (neg)
		num = -n;
	while (length-- > 0)
	{
		res[length] = num % 10 + '0';
		num = num / 10;
	}
	if (neg)
		res[0] = '-';
	res[check_length(n)] = '\0';
	return (res);
}
