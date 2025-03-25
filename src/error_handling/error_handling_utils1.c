/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:30:46 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/25 15:56:31 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_length_of_array(char **array)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (array[i++])
		counter++;
	return (counter);
}

char	**get_number_array(t_appdata *appdata, char *string)
{
	char	*cleared_line;
	char	**splitted_numbers;

	cleared_line = remove_extra_spaces(string);
	splitted_numbers = ft_split(cleared_line, ',');
	free(cleared_line);
	if (count_length_of_array(splitted_numbers) != 3)
	{
		free_char_array(splitted_numbers);
		ft_putstr_fd(INVALID_RGB_AMOUNT, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	return (splitted_numbers);
}

int	is_png_file(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'g' || str[i - 1] != 'n'
		|| str[i - 2] != 'p'
		|| str[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

int	count_identifiers(t_appdata *appdata, char *identifier)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < appdata->map->map_lines_total)
	{
		if (ft_strnstr(appdata->map->whole_map[i], identifier,
				ft_strlen(appdata->map->whole_map[i])))
			
		{
			counter++;
			if (identifier[0] == 'F' || identifier[0] == 'C')
				check_numeric(appdata, appdata->map->whole_map[i]);
			if (ft_strchr("NSEW", identifier[0]))
			{
				if (is_png_file(appdata->map->whole_map[i]) == FALSE)
					return (-1);
			}
		}
		i++;
	}
	return (counter);
}

char	**copy_array(char **array, int array_len)
{
	int		i;
	int		j;
	char	**copy;

	i = 6;
	j = 0;
	copy = (char **)malloc(sizeof(char *) * (array_len - 4));
	if (!copy)
		return (ft_putstr_fd(ALLOC_ERROR, 2), NULL);
	while (i < array_len)
	{
		copy[j] = ft_strdup(array[i]);
		if (!copy[j])
		{
			while (--j >= 0)
				free(copy[j]);
			free(copy);
			ft_putstr_fd(ALLOC_ERROR, 2);
			return (NULL);
		}
		j++;
		i++;
	}
	copy[j] = NULL;
	return (copy);
}

int	*create_row_len_array(char **array)
{
	int	*int_array;
	int	len_of_array;
	int	i;

	len_of_array = count_length_of_array(array);
	int_array = malloc(sizeof(int) * len_of_array);
	if (!int_array)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		return (NULL);
	}
	i = 0;
	while (i < len_of_array)
	{
		int_array[i] = (int)ft_strlen(array[i]);
		i++;
	}
	return (int_array);
}
