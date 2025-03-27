/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:56:01 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/27 16:03:37 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_appdata	appdata;

	if (argc != 2)
	{
		ft_putstr_fd(WRONG_ARGS_MSG, 2);
		exit(FAILURE);
	}
	if (is_valid_filename(argv[1]) == FALSE)
	{
		ft_putstr_fd(NO_CUB_MSG, 2);
		exit(FAILURE);
	}
	init_appdata(&appdata);
	parse_map(&appdata, argv[1]);
	check_for_errors(&appdata);
	fill_the_structs(&appdata);
// added by Y:
// function call put here for testing purpose, might be elsewhere once tested
	iterate_casted_rays(&appdata);
	start_mlx(&appdata);
}
