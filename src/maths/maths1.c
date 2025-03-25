/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrouzaud <yrouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/03/24 16:31:20 by yrouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// the math library header is to be added in the header file
// #include <math.h> //ok

//float	PI; //ok PI
//PI = 3.141592653589793; //ok as a define

// Constant and variable initialization, to be moved in relevant file.s and 
// struct.s later.

// arbitrary chosen constant:
//int	field_of_view_deg; //ok
//int	field_of_view_rad; //ok
//int	eyes_height; //ok
//int	move_speed; //ok already there
//float	turn_speed; //ok already there

//int	unit_size; //ok

//int	SCREEN_WIDTH; //ok
//int	SCREEN_HEIGHT; //ok

//float	angle_between_rays_rad; // ok
//float	dist_to_plane; //ok

// values extracted from the map:
//int	camera_position; // ok already there
//float	camera_position_rad; // ok
//int	pos_x_and_pos_y[2]; // already there. IMPORTANT: in project, 2 values: pos_x and pos_y
//int	pos_x_and_pos_y_units[2]; // already there ok IMPORTANT: in project, 2 separate values



//field_of_view_deg = 60;
//field_of_view_rad = degrees_to_radians(field_of_view_deg);
//eyes_height = unit_size / 2;
//move_speed = 10;
//turn_speed = ... ;		to be chosen

// camera_position = ... ;		to be extracted from map
// camera_position_rad = ... ;		to be calculated from degrees var

// pos_x_and_pos_y = ... ;				to be extracted from map
// pos_x_and_pos_y_units = ... ;			to be calculated with unit_size var

//unit_size = 64;

//SCREEN_HEIGHT = 400 * 4; // OK as a define
//SCREEN_WIDTH = 640 * 4; // OK as a define

//angle_between_rays_rad = field_of_view_rad / SCREEN_WIDTH;

//dist_to_plane = (SCREEN_WIDTH / 2) / tan(field_of_view_rad);


//ABOVE OK


float	set_ray_angle(int casted_ray_index)
{
	float	current_ray_angle_rad;

	current_ray_angle_rad = (camera_position_rad - (field_of_view_rad / 2)) + (casted_ray_index * angle_between_rays_rad);
	return (current_ray_angle_rad);
}

float	set_alpha_angle(float current_ray_angle)
{
	float	alpha_angle_rad;

	if (current_ray_angle < (PI / 2))
		alpha_angle_rad = current_ray_angle;
	else if (current_ray_angle < PI)
		alpha_angle_rad = current_ray_angle - (PI / 2);
	else if (current_ray_angle < ((3 * PI) / 2))
		alpha_angle_rad = current_ray_angle - PI;
	else
		alpha_angle_rad = current_ray_angle - ((3 * PI) / 2);
	return (alpha_angle_rad);
}

int	*find_1st_h_inters_coord(float current_ray_angle)
{
	int	first_intersection_coord[2];

	if (current_ray_angle < PI)
		first_intersection_coord[1] = floor(pos_x_and_pos_y[1] / unit_size) * unit_size - 1; // Shouldn't floor includes all?
	else
		first_intersection_coord[1] = floor(pos_x_and_pos_y[1] / unit_size) * unit_size + 64; // Shouldn't floor includes all?
	first_intersection_coord[0] = (pos_x_and_pos_y[1] - first_intersection_coord[1]) / tan(set_alpha_angle(current_ray_angle));
	return (first_intersection_coord)
}

int	*find_next_h_inters_coord(float current_ray_angle, int first_intersection_coord[2], int iteration)
{
	int	next_intersection_coord[2];
	int	y_increment_value;
	float	x_increment_value;

	if (current_ray_angle < PI)
		y_increment_value = - unit_size;
	else
		y_increment_value = unit_size;
	x_increment_value = unit_size / tan(set_alpha_angle(current_ray_angle));
	next_intersection_coord[0] = (first_intersection_coord[0] + (x_increment_value * iteration)) / unit_size;
	next_intersection_coord[1] = (first_intersection_coord[1] + (y_increment_value * unit_size)) / unit_size
	return (next_intersection_coord);
}

int	*find_1st_v_inters_coord(float current_ray_angle)
{
	int	first_intersection_coord[2];

	if (current_ray_angle > (PI / 2) && current_ray_angle < (3 * PI / 2))
		first_intersection_coord[0] = floor(pos_x_and_pos_y[0] / unit_size) * unit_size - 1; // Shouldn't floor includes all?
	else
		first_intersection_coord[0] = floor(pos_x_and_pos_y[0] / unit_size) * unit_size + 64; // Shouldn't floor includes all?
	first_intersection_coord[1] = (pos_x_and_pos_y[0] - first_intersection_coord[0]) / tan(set_alpha_angle(current_ray_angle));
	return (first_intersection_coord)
}

int	*find_next_v_inters_coord(float current_ray_angle, int first_intersection_coord[2], int iteration)
{
	int	next_intersection_coord[2];
	int	y_increment_value;
	float	x_increment_value;

	if (current_ray_angle > (PI / 2) && current_ray_angle < (3 * PI / 2))
		x_increment_value = - unit_size;
	else
		x_increment_value = unit_size;
	y_increment_value = unit_size * tan(set_alpha_angle(current_ray_angle));
	next_intersection_coord[0] = (first_intersection_coord[0] + (x_increment_value * iteration)) / unit_size;
	next_intersection_coord[1] = (first_intersection_coord[1] + (y_increment_value * unit_size)) / unit_size
	return (next_intersection_coord);
}

// This function is to be built taking into account system built by Vita
//	regarding the map and its parsing.
int	check_if_wall_at(int coordinates[2])
{
	......
	......
	......
	if (......)
		return (1);
	else
		return (0);
}

float	calc_wall_distance(float current_ray_angle, int intersection_x)
{
	float	distance_to_wall;

	distance_to_wall = abs(pos_x_and_pos_y[0] - intersection_x) / cos(set_alpha_angle(current_ray_angle));
	return(distance_to_wall);
}

float	first_horizont_wall_dist(float current_ray_angle)
{
	int	first_intersection_coord[2];
	int	next_intersection_coord[2];
	int	iterations_before_wall;

	iterations_before_wall = 1;
	first_intersection_coord = find_1st_h_inters_coord(current_ray_angle); // will not work like this, need to use pointer instead, but the idea is the same
	if (check_if_wall_at(first_intersection_coord) == 1)
		return (calc_wall_distance(current_ray_angle, first_intersection_coord[0]));
	while (check_if_wall_at(next_intersection_coord) == 0)
	{
		next_intersection_coord = find_next_h_inters_coord(current_ray_angle, iterations_before_wall);  // will not work like this, need to use pointer instead, but the idea is the same
		iterations_before_wall++;
	}
	return(calc_wall_distance(current_ray_angle, next_intersection_coord[0]));
}

float	first_vertical_wall_dist(float current_ray_angle)
{
	int	first_intersection_coord[2];
	int	next_intersection_coord[2];
	int	iterations_before_wall;

	iterations_before_wall = 1;
	first_intersection_coord = find_1st_v_inters_coord(current_ray_angle); // will not work like this, need to use pointer instead, but the idea is the same
	if (check_if_wall_at(first_intersection_coord) == 1)
		return (calc_wall_distance(current_ray_angle, first_intersection_coord[0]));
	while (check_if_wall_at(next_intersection_coord) == 0)
	{
		next_intersection_coord = find_next_v_inters_coord(current_ray_angle, iterations_before_wall); // will not work like this, need to use pointer instead, but the idea is the same
		iterations_before_wall++;
	}
	return(calc_wall_distance(current_ray_angle, next_intersection_coord[0]));
}

//QUESTION: what should be done if both vertical and horizontal are equidistant?
float	closest_wall_distance(float current_ray_angle)
{
	float	dist_to_1st_vertical_wall;
	float	dist_to_1st_horizont_wall;

	dist_to_1st_horizont_wall = first_horizont_wall_dist(current_ray_angle);
	dist_to_1st_vertical_wall = first_vertical_wall_dist(current_ray_angle);
	if (dist_to_1st_horizont_wall > dist_to_1st_vertical_wall)
		return (dist_to_1st_horizont_wall);
	else
		return (dist_to_1st_vertical_wall);
}

float	correct_fishbowl_effect(float closest_wall_distance, float current_ray_angle)
{
	float	corrected_distance;
	float	beta_angle;
	
	beta_angle = abs(current_ray_angle - camera_position_rad);
	corrected_distance = closest_wall_distance * cos(beta_angle);
	return (corrected_distance);
}


// BELOW OK

void	wall_height_for_drawing(t_appdata *appdata)
{
//	int	projected_slice_height;
//	int	slice_starting_point;
//	int	slice_ending_point;

	appdata->raycast->projected_slice_height = roundf(appdata->map->unit_size / appdata->raycast->closest_wall_corrected) * appdata->raycast->dist_to_plane;
	appdata->raycast->slice_starting_point = (SCREEN_HEIGHT / 2) - (appdata->raycast->projected_slice_height / 2);
	appdata->raycast->slice_end_point = appdata->raycast->slice_starting_point + appdata->raycast->projected_slice_height;
}

void	iterate_casted_rays(t_appdata *appdata)
{
	int	casted_ray_index;
//	float	current_ray_angle;
//	float	closest_wall_dist;
//	float	closest_wall_corrected;

	casted_ray_index = 0;
	while (casted_ray_index < SCREEN_WIDTH)
	{
		appdata->raycast->curr_ray_angle = set_ray_angle(casted_ray_index);
		appdata->raycast->closest_wall_dist = closest_wall_distance(appdata->raycast->curr_ray_angle);
		appdata->raycast->closest_wall_corrected = correct_fishbowl_effect(appdata->raycast->closest_wall_dist, appdata->raycast->curr_ray_angle);
		wall_height_for_drawing(appdata);

		// CALL MLX DRAWING FUNCTION(S) HERE?
		// + TEXTURE FUNCTION(S) HERE TOO?

		casted_ray_index++;
	}
}


// void	player_moving()
// {
// 	.....
// }
