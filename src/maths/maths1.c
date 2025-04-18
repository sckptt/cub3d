/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitakinsfator <vitakinsfator@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/03/27 17:41:58 by vitakinsfat      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TO DO NOW:
// ==========
// - Integrate a call to the maths process in the existing main loop
// - Build functions to extract the following values:
// 		camera_position = ... ;		to be extracted from map
// 		camera_position_rad = ... ;		to be calculated from degrees var
// 		pos_x_and_pos_y = ... ;				to be extracted from map
// 		pos_x_and_pos_y_units = ... ;			to be calculated with unit_size var
// - Build the function (or Vita's one) to check if there is a wall at a given coord
// - Print the main values to see if no mistakes in current maths formulas
// - Integrate the drawing in the main loop of the maths function;
// - Check if there is no too long function;
// - Put the maths functions in different files to respect the 5 functions limit;
// - Deal with too long lines (more than 80 chars);
// - See how to implement the textures

float	set_ray_angle(int casted_ray_index, t_appdata *appdata)
{
	float	current_ray_angle_rad;

	appdata->raycast->angle_btw_rays_rad = appdata->player->field_of_view_rad / SCREEN_WIDTH;
	printf("ABR_D is %d\n", ABR_D);
	printf("FOV_R %i\n", appdata->player->field_of_view_rad);
	printf("CRI %i\n", casted_ray_index);
	printf("ABR_R %f\n\n", appdata->raycast->angle_btw_rays_rad);
	current_ray_angle_rad = (appdata->player->camera_position_rad - (appdata->player->field_of_view_rad / 2)) + (casted_ray_index * appdata->raycast->angle_btw_rays_rad);
	return (current_ray_angle_rad);
}

float	set_alpha_angle(t_appdata *appdata)
{
	float	alpha_angle_rad;

	if (appdata->raycast->curr_ray_angle < (PI / 2))
		alpha_angle_rad = appdata->raycast->curr_ray_angle;
	else if (appdata->raycast->curr_ray_angle < PI)
		alpha_angle_rad = appdata->raycast->curr_ray_angle - (PI / 2);
	else if (appdata->raycast->curr_ray_angle < ((3 * PI) / 2))
		alpha_angle_rad = appdata->raycast->curr_ray_angle - PI;
	else
		alpha_angle_rad = appdata->raycast->curr_ray_angle - ((3 * PI) / 2);
	return (alpha_angle_rad);
}

void	find_1st_h_inters_coord(t_appdata *appdata)
{
	if (appdata->raycast->curr_ray_angle < PI)
		appdata->raycast->first_h_intersection_coord_y = floor(appdata->player->pos_y / appdata->map->unit_size) * appdata->map->unit_size - 1; 
// ^^Shouldn't floor() includes all?^^
	else
		appdata->raycast->first_h_intersection_coord_y = floor(appdata->player->pos_y / appdata->map->unit_size) * appdata->map->unit_size + 64; 
// ^^Shouldn't floor() includes all?^^
	appdata->raycast->first_h_intersection_coord_x = (appdata->player->pos_y - appdata->raycast->first_h_intersection_coord_y) / tan(set_alpha_angle(appdata));
}

void	find_next_h_inters_coord(t_appdata *appdata, int iteration)
{
	int	y_increment_value;
	float	x_increment_value;

	if (appdata->raycast->curr_ray_angle < PI)
		y_increment_value = - appdata->map->unit_size;
	else
		y_increment_value = appdata->map->unit_size;
	x_increment_value = appdata->map->unit_size / tan(set_alpha_angle(appdata));
	appdata->raycast->next_h_intersection_coord_x = (appdata->raycast->first_h_intersection_coord_x + (x_increment_value * iteration)) / appdata->map->unit_size;
	appdata->raycast->next_h_intersection_coord_y = (appdata->raycast->first_h_intersection_coord_y + (y_increment_value * appdata->map->unit_size)) / appdata->map->unit_size;
}

void	find_1st_v_inters_coord(t_appdata *appdata)
{
	if (appdata->raycast->curr_ray_angle > (PI / 2) && appdata->raycast->curr_ray_angle < (3 * PI / 2))
		appdata->raycast->first_v_intersection_coord_x = floor(appdata->player->pos_x / appdata->map->unit_size) * appdata->map->unit_size - 1; 
// ^^Shouldn't floor() includes all?^^
	else
		appdata->raycast->first_v_intersection_coord_x = floor(appdata->player->pos_x / appdata->map->unit_size) * appdata->map->unit_size + 64; 
// ^^Shouldn't floor() includes all?^^
	appdata->raycast->first_v_intersection_coord_y = (appdata->player->pos_x - appdata->raycast->first_v_intersection_coord_x) / tan(set_alpha_angle(appdata));
}

void	find_next_v_inters_coord(t_appdata *appdata, int iteration)
{
	int	y_increment_value;
	float	x_increment_value;

	if (appdata->raycast->curr_ray_angle > (PI / 2) && appdata->raycast->curr_ray_angle < (3 * PI / 2))
		x_increment_value = - appdata->map->unit_size;
	else
		x_increment_value = appdata->map->unit_size;
	y_increment_value = appdata->map->unit_size * tan(set_alpha_angle(appdata));
	appdata->raycast->next_v_intersection_coord_x = (appdata->raycast->first_v_intersection_coord_x + (x_increment_value * iteration)) / appdata->map->unit_size;
	appdata->raycast->next_v_intersection_coord_y = (appdata->raycast->first_v_intersection_coord_y + (y_increment_value * appdata->map->unit_size)) / appdata->map->unit_size;
}

//ABOVE OK

// This function is to be built taking into account system built by Vita
//	regarding the map and its parsing.
int	check_if_wall_at(t_appdata *appdata)
{
	// ......
	// ......
	// ......
	// if (......)
	if (appdata != NULL)
		return (1);
	else
		return (0);
	// else
	// 	return (0);
}

// BELOW OK

float	calc_wall_distance(t_appdata *appdata, int intersection_x)
{
	float	distance_to_wall;

	distance_to_wall = abs(appdata->player->pos_x - intersection_x) / cos(set_alpha_angle(appdata));
	return(distance_to_wall);
}

float	first_horizont_wall_dist(t_appdata *appdata)
{
	int	iterations_before_wall;

	iterations_before_wall = 1;
	find_1st_h_inters_coord(appdata);
	if (check_if_wall_at(appdata) == 1)
		return (calc_wall_distance(appdata, appdata->raycast->first_h_intersection_coord_x));
	while (check_if_wall_at(appdata) == 0)
	{
		find_next_h_inters_coord(appdata, iterations_before_wall);
		iterations_before_wall++;
	}
	return(calc_wall_distance(appdata, appdata->raycast->next_h_intersection_coord_x));
}

float	first_vertical_wall_dist(t_appdata *appdata)
{
	int	iterations_before_wall;
	
	iterations_before_wall = 1;
	find_1st_v_inters_coord(appdata);
	if (check_if_wall_at(appdata) == 1)
		return (calc_wall_distance(appdata, appdata->raycast->first_v_intersection_coord_x));
	while (check_if_wall_at(appdata) == 0)
	{
		find_next_v_inters_coord(appdata, iterations_before_wall);
		iterations_before_wall++;
	}
	return(calc_wall_distance(appdata, appdata->raycast->next_v_intersection_coord_x));
}

//QUESTION: what should be done if both vertical and horizontal are equidistant?
float	closest_wall_distance(t_appdata *appdata)
{
	float	dist_to_1st_vertical_wall;
	float	dist_to_1st_horizont_wall;

	dist_to_1st_horizont_wall = first_horizont_wall_dist(appdata);
	dist_to_1st_vertical_wall = first_vertical_wall_dist(appdata);
	if (dist_to_1st_horizont_wall > dist_to_1st_vertical_wall)
		return (dist_to_1st_horizont_wall);
	else
		return (dist_to_1st_vertical_wall);
}

float	correct_fishbowl_effect(t_appdata *appdata)
{
	float	corrected_distance;
	float	beta_angle;
	
	beta_angle = fabsf(appdata->raycast->curr_ray_angle - appdata->player->camera_position_rad);
	corrected_distance = appdata->raycast->closest_wall_dist * cos(beta_angle);
	return (corrected_distance);
}

void	wall_height_for_drawing(t_appdata *appdata)
{
	appdata->raycast->projected_slice_height = roundf(appdata->map->unit_size / appdata->raycast->closest_wall_corrected) * appdata->raycast->dist_to_plane;
	appdata->raycast->slice_starting_point = (SCREEN_HEIGHT / 2) - (appdata->raycast->projected_slice_height / 2);
	appdata->raycast->slice_end_point = appdata->raycast->slice_starting_point + appdata->raycast->projected_slice_height;
}

void	iterate_casted_rays(t_appdata *appdata)
{
	int	casted_ray_index;

	casted_ray_index = 0;
	appdata->raycast->angle_btw_rays_rad = appdata->player->field_of_view_rad / SCREEN_WIDTH;
	appdata->raycast->dist_to_plane = (SCREEN_WIDTH / 2) / tan(appdata->player->field_of_view_rad);
	while (casted_ray_index < SCREEN_WIDTH)
	{
		appdata->raycast->curr_ray_angle = set_ray_angle(casted_ray_index, appdata);
		printf("Ray angle: %f\n", appdata->raycast->curr_ray_angle);
		appdata->raycast->closest_wall_dist = closest_wall_distance(appdata);
		appdata->raycast->closest_wall_corrected = correct_fishbowl_effect(appdata);
		wall_height_for_drawing(appdata);
		// CALL MLX DRAWING FUNCTION(S) HERE?
		// + TEXTURE FUNCTION(S) HERE TOO?
		printf("Current ray index is %i\n", casted_ray_index);
		printf("Current ray angle is %f\n", appdata->raycast->curr_ray_angle);
		printf("Closest wall distance is %f\n", appdata->raycast->closest_wall_dist);
		printf("Undistorted val is %f\n\n", appdata->raycast->closest_wall_corrected);
		sleep(1);
		casted_ray_index++;
	}
}

// void	player_moving()
// {
// 	.....
// }
