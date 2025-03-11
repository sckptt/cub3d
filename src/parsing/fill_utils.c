/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:36 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/11 16:31:24 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int *get_rgb_colors(char *string)
{
	char **splitted_string;
	char **rgb_array;
	int *rgb_int;
	int i;
	
	splitted_string = ft_split(string, ' ');
	if (!splitted_string)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	rgb_array = ft_split(splitted_string[1], ',');
	if (!rgb_array)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	free_char_array(splitted_string);
	rgb_int = malloc(sizeof(int) * 3);
	if (!rgb_int)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	i = -1;
	while (++i < 3)
	{
		rgb_int[i] = ft_atoi(rgb_array[i]);
		if (rgb_int[i] > 255)
			return (ft_putstr_fd(INVALID_RGB_VALUES, 2),
		free_char_array(rgb_array), free(rgb_int), NULL);
	}
	free_char_array(rgb_array);
	return (rgb_int);
}

char *get_path(char *string)
{
	char **splitted_string;
	char *path_to_texture;
	
	splitted_string = ft_split(string, ' ');
	if (!splitted_string)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	path_to_texture = ft_strdup(splitted_string[1]);
	if (!path_to_texture)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	free_char_array(splitted_string);
	return (path_to_texture);
}
