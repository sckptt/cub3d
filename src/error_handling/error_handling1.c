/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:40:00 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/11 14:00:05 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//We have shit tone of places where it can go wrong!
//Missing things, duplicates, non-numeric values (where it requires to be
//numeric). I don't check map errors (like missing player, more than 1 player,
//extra symbols, no walls etc) yet. But some error cases are working well.
//Next step - check the map. 

//TODO - whitespace cases like "XX,   XX,XX"
static void	check_numeric(t_appdata *appdata, char *string)
{
	int		i;
	size_t	j;
	char	**splitted_numbers;

	i = 0;
	splitted_numbers = get_number_array(string);
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
	if (check_map(appdata) == FAILURE)
	{
		free_appdata(appdata);
		exit(FAILURE);
	}
}
