/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:30:36 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/25 16:18:25 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*remove_extra_spaces(char *string)
{
	char arr[12];
	char *res;
	int i;
	int j;

	i = 0;
	j = 0;
	while (!ft_isdigit(string[i]))
		i++;
	while (string[i])
	{
		if (ft_isdigit(string[i]) || string[i] == ',' || string[i] == '-')
			arr[j++] = string[i++];
		else
			i++;
	}
	arr[j] = '\0';
	res = ft_strdup(arr);
	return (res);
}

int	*get_rgb_colors(char *string)
{
	char	*cleared_string;
	char	**rgb_array;
	int		*rgb_int;
	int		i;

	cleared_string = remove_extra_spaces(string);
	if (!cleared_string)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	rgb_array = ft_split(cleared_string, ',');
	if (!rgb_array)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	free(cleared_string);
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

char	*get_path(char *string)
{
	char	**splitted_string;
	char	*path_to_texture;

	splitted_string = ft_split(string, ' ');
	if (!splitted_string)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	path_to_texture = ft_strdup(splitted_string[1]);
	if (!path_to_texture)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	free_char_array(splitted_string);
	return (path_to_texture);
}

int count_width(char **map)
{
	int i;
	int width;
	size_t str_width;

	i = -1;
	width = 0;
	while (map[++i])
	{
		str_width = ft_strlen(map[i]);
		if ((int)str_width > width)
			width = (int)str_width;
	}
	return (width);
}
