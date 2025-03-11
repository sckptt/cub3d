/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:37 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/11 11:44:45 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_the_wall(t_map_data *map)
{
	
}

int check_extra_symbols(t_map_data *map)
{
	int i;
	int j;

	i = 6;
	while (i < map->map_lines_total)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (map->whole_map[i][j] != 'N' && map->whole_map[i][j] != 'S'
			&& map->whole_map[i][j] != 'W' && map->whole_map[i][j] != 'E'
			&& map->whole_map[i][j] != '1' && map->whole_map[i][j] != '0'
			&& map->whole_map[i][j] != ' ')
				return (ft_putstr_fd(EXTRA_SYMBOLS_MSG, 2), FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int check_player(t_map_data *map)
{
	int i;
	int j;
	int player_counter;

	i = 6;
	player_counter = 0;
	while (i < map->map_lines_total)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (map->whole_map[i][j] == 'N' || map->whole_map[i][j] == 'S'
			|| map->whole_map[i][j] == 'W' || map->whole_map[i][j] == 'E')
				player_counter++;
			j++;
		}
		i++;
	}
	if (player_counter == 0)
		return(ft_putstr_fd(MISSING_PLAYER, 2), FAILURE);
	else if (player_counter > 1)
		return(ft_putstr_fd(MULTIPLE_PLAYERS, 2), FAILURE);
	return (SUCCESS);
}

int check_map(t_appdata *appdata)
{
	if (appdata->map->map_lines_total <= 6)
	{
		ft_putstr_fd(MISSING_MAP, 2);
		return(FAILURE);
	}
	if (check_player(appdata->map) == FAILURE)
		return(FAILURE);
	if (check_extra_symbols(appdata->map) == FAILURE)
		return(FAILURE);
	// if (check_the_wall(appdata->map) == FAILURE)
	// 	return(FAILURE);
	return (SUCCESS);
}
