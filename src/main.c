/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinsfat <vkinsfat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:56:01 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/13 18:23:22 by vkinsfat         ###   ########.fr       */
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
	free_appdata(&appdata);
	start_mlx(&appdata);
}


