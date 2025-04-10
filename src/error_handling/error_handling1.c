/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:40:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/04/10 17:24:15 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_numeric(t_appdata *appdata, char *string)
{
	int		i;
	size_t	j;
	char	**splitted_numbers;

	i = 0;
	splitted_numbers = get_number_array(appdata, string);
	while (splitted_numbers[i] != NULL)
	{
		j = 0;
		while (j < (ft_strlen(splitted_numbers[i]) - 1))
		{
			if (!ft_isdigit(splitted_numbers[i][j]))
			{
				free_char_array(splitted_numbers);
				free_appdata(appdata);
				ft_putstr_fd(INVALID_RGB_VALUES, 2);
				exit(FAILURE);
			}
			j++;
		}
		i++;
	}
	free_char_array(splitted_numbers);
}

int is_map_started(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (FALSE);
	}
	return (TRUE);
}

int check_extra_id(t_appdata *appdata)
{
	int i;
	char **split_line;

	i = -1;
	while (++i < appdata->map->map_lines_total)
	{
		if (is_map_started(appdata->map->whole_map[i]) == TRUE)
			break ;
		split_line = ft_split(appdata->map->whole_map[i], ' ');
		if (!ft_strnstr("NOSOWEEAFC", split_line[0], ft_strlen("NOSOWEEAFC")))
		{
			free_char_array(split_line);
			return (FAILURE);
		}
		free_char_array(split_line);
	}
	return (SUCCESS);
}

static int	check_paths(t_appdata *appdata)
{
	int	north;
	int	south;
	int	east;
	int	west;

	north = count_identifiers(appdata, "NO ");
	south = count_identifiers(appdata, "SO ");
	east = count_identifiers(appdata, "WE ");
	west = count_identifiers(appdata, "EA ");
	if (north == 0 || south == 0 || east == 0 || west == 0)
		return (ft_putstr_fd(MISSING_TEXTURE, 2), FAILURE);
	else if (north > 1 || south > 1 || east > 1 || west > 1)
		return (ft_putstr_fd(TEXTURE_DUPLICATE, 2), FAILURE);
	else if (north == -1 || south == -1 || east == -1 || west == -1)
		return (ft_putstr_fd(NON_PNG_TEXTURE, 2), FAILURE);
	else if (north == -2 || south == -2 || east == -2 || west == -2)
		return (ft_putstr_fd(WRONG_ID_ORDER, 2), FAILURE);
	else if (check_extra_id(appdata) == FAILURE)
		return (ft_putstr_fd(WRONG_IDENTIFIER, 2), FAILURE);
	return (SUCCESS);
}

static int	check_colors(t_appdata *appdata)
{
	int	floor;
	int	ceiling;

	floor = count_identifiers(appdata, "F ");
	ceiling = count_identifiers(appdata, "C ");
	if (floor == 0 || ceiling == 0)
		return (ft_putstr_fd(MISSING_COLOR, 2), FAILURE);
	else if (floor > 1 || ceiling > 1)
		return (ft_putstr_fd(COLOR_DUPLICATE, 2), FAILURE);
	return (SUCCESS);
}

int	is_valid_filename(const char *arg)
{
	int	i;

	i = ft_strlen(arg) - 1;
	if (arg[i] != 'b' || arg[i - 1] != 'u'
		|| arg[i - 2] != 'c'
		|| arg[i - 3] != '.')
		return (FALSE);
	return (TRUE);
}

void	check_for_errors(t_appdata *appdata)
{
	if (check_paths(appdata) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (check_colors(appdata) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (check_order(appdata) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (check_map(appdata) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
}
