/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:15:46 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:12 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = (char)c;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		else
			str++;
	}
	return (NULL);
}
