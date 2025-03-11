/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:39:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/10 18:45:34 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int count_length_of_array(char **array)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (array[i++])
		counter++;
	return (counter);
}

char **get_number_array(char *string)
{
	char **splitted_line;
	char **splitted_numbers;
	
	splitted_line = ft_split(string, ' ');
	splitted_numbers = ft_split(splitted_line[1], ',');
	free_char_array(splitted_line);
	if (count_length_of_array(splitted_numbers) != 3)
	{
		free_char_array(splitted_numbers);
		//free appdata;
		ft_putstr_fd(INVALID_RGB_AMOUNT, 2);
		exit(1);
	}
	return (splitted_numbers);
}
int count_identifiers(t_appdata *appdata, char *identifier)
{
	int i;
	int counter;

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
		}
		i++;
	}
	return (counter);
}
