/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:11:20 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/09 18:55:14 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0')
		i++;
	size = i + 1;
	dup = (char *) malloc(size);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
