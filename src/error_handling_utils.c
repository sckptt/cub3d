/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:39:44 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/09 21:45:21 by vitakinsfat      ###   ########.fr       */
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
	//free splitted line
	if (count_length_of_array(splitted_numbers) != 3)
	{
		//free splitted numbers
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
	while (i < appdata->map_lines_total)
	{
		if (ft_strnstr(appdata->whole_map[i], identifier,
			ft_strlen(appdata->whole_map[i])))
		{
			counter++;
			if (identifier[0] == 'F' || identifier[0] == 'C')
				check_numeric(appdata, appdata->whole_map[i]);
		}
		i++;
	}
	return (counter);
}
