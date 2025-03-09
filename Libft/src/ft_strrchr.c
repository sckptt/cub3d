/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:12:11 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:44 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		else
			i--;
	}
	return (NULL);
}
