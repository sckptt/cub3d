/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:56:01 by vitakinsfat       #+#    #+#             */
/*   Updated: 2025/03/09 18:07:08 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_appdata(t_appdata **appdata)
{
	t_appdata *node;

	node = malloc(sizeof(t_appdata));
	if (!node)
	{
		ft_putstr_fd(ALLOC_ERROR, 2);
		exit(1);
	}
	node->map = NULL;
	node->n_texture = NULL;
	node->s_texture = NULL;
	node->w_texture = NULL;
	node->e_texture = NULL;
	node->floor_colors = 0;
	node->ceiling_colors = 0;
	*appdata = node;
}

int main(int argc, char **argv)
{
	t_appdata *appdata;
	
	if (argc != 2)
	{
		ft_putstr_fd(WRONG_ARGS_MSG, 2);
		exit(1);
	}
	init_appdata(&appdata);
	parse_map(appdata, argv[1]);
}
