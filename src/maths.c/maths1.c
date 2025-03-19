/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrouzaud <yrouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 09:31:20 by yrouzaud          #+#    #+#             */
/*   Updated: 2025/03/18 12:31:20 by yrouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// QUESTIONS TO VITA:
// - float or double or don't mind?
// - is the current structure(s) the final one, so that I can add var to it?
// - is there a "mother" struct to be passed to every function? If not, 
// - is the last version on github? If not, what are you planning to add to it?
// - working with branches? Should we? How does it works? Any tips/warnings?
// - about 2D and 3D calculations...?

// 640 * 4 * 400 * 4 is the final
// pixels texture 124

#include "cub3d.h"

// the math library header is to be added in the header file
#include <math.h>

float	pi;
pi = 3.141592653589793;

// Constant and variable initialization, to be moved in relevant file.s and 
// struct.s later.

// arbitrary chosen constant:
int	player_field_of_view_degr;
int	player_field_of_view_rad;
int	player_eyes_height;
int	player_moving_speed;
float	player_turning_speed;

int	unit_size;

int	projection_plane_width;
int	projection_plane_height;

float	angle_between_rays_rad;
float	distance_player_to_plane;

// values extracted from the map:
int	player_view_direction_deg;
float	player_view_direction_rad;
int	player_position_raw[2];
int	player_position_units[2];


player_field_of_view_degr = 60;
// player_field_of_view_rad = ... ;	to be calculated from degrees var
player_eyes_height = unit_size / 2;
player_moving_speed = 10;
//player_turning_speed = ... ;		to be chosen

// player_view_direction_deg = ... ;		to be extracted from map
// player_view_direction_rad = ... ;		to be calculated from degrees var

// player_position_raw = ... ;				to be extracted from map
// player_position_units = ... ;			to be calculated with unit_size var

unit_size = 64;

projection_plane_height = 400;
projection_plane_width = 640;

angle_between_rays_rad = player_field_of_view_rad / projection_plane_width;

distance_player_to_plane = (projection_plane_width / 2) / tan(player_field_of_view_rad);


float	degrees_to_radians(float value_in_degrees)
{
	float	value_in_radians;

	value_in_radians = value_in_degrees * (pi / 180);
	return (value_in_radiants);
}


float	set_ray_angle(int casted_ray_index)
{
	float	current_ray_angle_rad;

	current_ray_angle_rad = (player_view_direction_rad - (player_field_of_view_rad / 2)) + (casted_ray_index * angle_between_rays_rad);
	return (current_ray_angle_rad);
}

float	set_alpha_angle(float current_ray_angle)
{
	float	alpha_angle_rad;

	if (current_ray_angle < (pi / 2))
		alpha_angle_rad = current_ray_angle;
	else if (current_ray_angle < pi)
		alpha_angle_rad = current_ray_angle - (pi / 2);
	else if (current_ray_angle < ((3 * pi) / 2))
		alpha_angle_rad = current_ray_angle - pi;
	else
		alpha_angle_rad = current_ray_angle - ((3 * pi) / 2);
	return (alpha_angle_rad);
}

int	*find_1st_inters_coord(float current_ray_angle)
{
	int	first_intersection_coord[2];

	if (....)
	{
		if (current_ray_angle < pi)
			first_intersection_coord[1] = floor(player_position_raw[1] / unit_size) * unit_size - 1; // Shouldn't floor includes all?
		else
			first_intersection_coord[1] = floor(player_position_raw[1] / unit_size) * unit_size + 64; // Shouldn't floor includes all?
		first_intersection_coord[0] = (player_position_raw[1] - first_intersection_coord[1]) / tan(set_alpha_angle(current_ray_angle));
	}
	else
	{
....
	}
	return (first_intersection_coord)
}

int	*find_next_inters_coord(float current_ray_angle, int first_intersection_coord[2], int iteration)
{
	int	next_intersection_coord[2];
	int	y_increment_value;
	float	x_increment_value;

	if (current_ray_angle < pi)
		y_increment_value = unit_size;
	else
		y_increment_value = - unit_size;
	x_increment_value = unit_size / tan(set_alpha_angle(current_ray_angle));
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

	distance_horiz_wall = abs(player_position_raw[0] - intersection_x) / cos(set_alpha_angle(current_ray_angle));
	return(distance_to_wall);
}

float	first_horizont_wall_dist(float current_ray_angle)
{
	int	first_intersection_coord[2];
	int	next_intersection_coord[2];
	float	dist_to_1st_horizont_wall;
	int	iteration_before_wall;

	iteration_before_wall = 0;
	first_intersection_coord = find_1st_inters_coord(current_ray_angle); // will not work like this, need to use pointer instead, but the idea is the same
	if (check_if_wall_at(first_intersection_coord) == 1)
		return (calc_wall_distance(current_ray_angle, first_horizont_wall_dist[0]));
	while (check_if_wall_at(next_intersection_coord) == 0)
	{
		next_intersection_coord = find_next_inters_coord(current_ray_angle, iteration_before_wall);  // will not work like this, need to use pointer instead, but the idea is the same
		iteration_before_wall++;
	}
	return(calc_wall_distance(current_ray_angle, next_intersection_coord[0]));
}

float	first_vertical_wall_dist()
{
	float	dist_to_1st_vertical_wall;

	.......
}

float	closest_wall_distance(float current_ray_angle)
{
	float	dist_to_1st_vertical_wall;
	float	dist_to_1st_horizont_wall;

	dist_to_1st_horizont_wall = first_horizont_wall_dist(current_ray_angle, .....);
	dist_to_1st_vertical_wall = first_vertical_wall_dist(, current_ray_angle.....);
	.........
}

void	iterate_casted_rays()
{
	int	casted_ray_index;
	float	current_ray_angle;

	casted_ray_index = 0;
	while (casted_ray_index < projection_plane_width)
	{
		current_ray_angle = set_ray_angle(casted_ray_index);

		closest_wall_distance(current_ray_angle, ........);
		.......

		ray_index++;
	}
}

int	main(void)
{

	return (0);
}