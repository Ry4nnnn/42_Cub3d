/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawray_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:38:06 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:47:39 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_x_y_offset(t_cub3d *data, t_ray *ray);
void	assign_direction(t_ray *ray);
void	assign_current_texture(t_cub3d *data, t_ray *ray);
void	assign_wall_height(t_cub3d *data, t_ray *ray);

/**
 * @brief Assign offsets for x and y based on ray direction.
 *
 * This function determines the step and initial offsets based on the 
 * ray direction.
 *
 * @param data The main data structure for the application.
 * @param ray The ray structure.
 */
void	assign_x_y_offset(t_cub3d *data, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->xo = (data->player->px - ray->mx) * ray->dx;
	}
	else
	{
		ray->stepx = 1;
		ray->xo = (ray->mx + 1.0 - data->player->px) * ray->dx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->yo = (data->player->py - ray->my) * ray->dy;
	}
	else
	{
		ray->stepy = 1;
		ray->yo = (ray->my + 1.0 - data->player->py) * ray->dy;
	}
}

/**
 * @brief Assign the direction of the hit (North/South or East/West).
 *
 * This function determines the direction of the wall hit 
 * (North/South or East/West).
 *
 * @param ray The ray structure.
 */
void	assign_direction(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->stepx == 1)
			ray->east_west = EAST;
		else
			ray->east_west = WEST;
	}
	else
	{
		if (ray->stepy == 1)
			ray->north_south = SOUTH;
		else
			ray->north_south = NORTH;
	}
}

/**
 * @brief Assign the current texture based on the hit direction.
 *
 * This function assigns the current texture based on the hit direction.
 *
 * @param data The main data structure for the application.
 * @param ray The ray structure.
 */
void	assign_current_texture(t_cub3d *data, t_ray *ray)
{
	if (ray->north_south != -1)
	{
		if (ray->north_south == NORTH)
			data->current_texture = data->texture->north;
		else
			data->current_texture = data->texture->south;
	}
	if (ray->east_west != -1)
	{
		if (ray->east_west == EAST)
			data->current_texture = data->texture->east;
		else
			data->current_texture = data->texture->west;
	}
}

/**
 * @brief Assign the height and endpoints of the wall segment to be drawn.
 *
 * This function determines the height and endpoints of the wall 
 * segment to be drawn.
 *
 * @param data The main data structure for the application.
 * @param ray The ray structure.
 */
void	assign_wall_height(t_cub3d *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perpwalldist = ray->xo - ray->dx;
	else
		ray->perpwalldist = ray->yo - ray->dy;
	ray->perpwalldist *= cos(ray->raydirx - data->player->dirx);
	ray->lineheight = (int)(SIZE_Y / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + SIZE_Y / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + SIZE_Y / 2;
	if (ray->drawend >= SIZE_Y)
		ray->drawend = SIZE_Y - 1;
}
