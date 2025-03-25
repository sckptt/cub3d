/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:37 by vkinsfat          #+#    #+#             */
/*   Updated: 2025/03/25 16:25:53 by vkinsfat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	flood_fill(t_appdata *appdata, int x, int y)
{
	if (x < 0 || y < 0 || y >= count_length_of_array(appdata->map->copy_map)
		|| x > appdata->map->row_len[y])
	{
		ft_putstr_fd(NO_WALL_MSG, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (appdata->map->copy_map[y][x] == ' ')
	{
		ft_putstr_fd(SPACE_FOUND, 2);
		free_appdata(appdata);
		exit(FAILURE);
	}
	if (x >= appdata->map->row_len[y] || appdata->map->copy_map[y][x] == '1'
		|| appdata->map->copy_map[y][x] == 'X')
		return ;
	appdata->map->copy_map[y][x] = 'X';
	flood_fill(appdata, x + 1, y);
	flood_fill(appdata, x - 1, y);
	flood_fill(appdata, x, y + 1);
	flood_fill(appdata, x, y - 1);
}

static int	check_the_wall(t_appdata *appdata)
{
	int		pos_x;
	int		pos_y;

	appdata->map->copy_map = copy_array(appdata->map->whole_map, appdata->map->map_lines_total);
	if (!appdata->map->copy_map)
		return (FAILURE);
	appdata->map->row_len = create_row_len_array(appdata->map->copy_map);
	if (!appdata->map->row_len)
		return (FAILURE);
	pos_x = find_position(appdata->map->copy_map, 'x');
	pos_y = find_position(appdata->map->copy_map, 'y');
	flood_fill(appdata, pos_x, pos_y);
	return (SUCCESS);
}

static int	check_extra_symbols(t_map_data *map)
{
	int	i;
	int	j;

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

static int	check_player(t_map_data *map)
{
	int	i;
	int	j;
	int	player_counter;

	i = 6;
	player_counter = 0;
	while (i < map->map_lines_total)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (ft_strchr("NSEW", map->whole_map[i][j]))
				player_counter++;
			j++;
		}
		i++;
	}
	if (player_counter == 0)
		return (ft_putstr_fd(MISSING_PLAYER, 2), FAILURE);
	else if (player_counter > 1)
		return (ft_putstr_fd(MULTIPLE_PLAYERS, 2), FAILURE);
	return (SUCCESS);
}

int	check_map(t_appdata *appdata)
{
	if (appdata->map->map_lines_total <= 6)
	{
		ft_putstr_fd(MISSING_MAP, 2);
		return (FAILURE);
	}
	if (check_player(appdata->map) == FAILURE)
		return (FAILURE);
	if (check_extra_symbols(appdata->map) == FAILURE)
		return (FAILURE);
	if (check_the_wall(appdata) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
