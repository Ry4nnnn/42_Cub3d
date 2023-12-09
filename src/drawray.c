/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:54:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 18:58:09 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_cub3d *data, t_ray *ray, int x, int w);
void	drawray(t_cub3d *data);

/**
 * @brief Initialize ray parameters for a specific column in the screen.
 *
 * This function initializes the ray parameters based on the player's 
 * position and direction for a specific column (x-coordinate) 
 * in the screen.
 *
 * @param data The main data structure for the application.
 * @param ray The ray structure to be initialized.
 * @param x The x-coordinate of the screen column.
 * @param w The total width of the screen.
 */
void	init_ray(t_cub3d *data, t_ray *ray, int x, int w)
{
	double	scale;

	ray->north_south = -1;
	ray->east_west = -1;
	scale = 2 * x / (double)w - 1;
	ray->raydirx = data->player->dirx + data->player->planex * scale;
	ray->raydiry = data->player->diry + data->player->planey * scale;
	ray->mx = (int)data->player->px;
	ray->my = (int)data->player->py;
	ray->dx = sqrt(1 + (ray->raydiry * ray->raydiry) \
			/ (ray->raydirx * ray->raydirx));
	ray->dy = sqrt(1 + (ray->raydirx * ray->raydirx) \
			/ (ray->raydiry * ray->raydiry));
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
 * @brief Perform raycasting and draw the resulting image.
 *
 * This function performs raycasting for each column in the screen and 
 * draws the resulting image.
 *
 * @param data The main data structure for the application.
 */
void	drawray(t_cub3d *data)
{
	t_ray	*ray;
	int		i;
	int		w;

	i = -1;
	w = SIZE_X;
	ray = data->ray;
	while (++i < w)
	{
		init_ray(data, ray, i, w);
		ray->hit = 0;
		while (ray->hit == 0)
		{
			if (ray->xo < ray->yo)
			{
				ray->xo += ray->dx;
				ray->mx += ray->stepx;
				ray->side = 0;
			}
			else
			{
				ray->yo += ray->dy;
				ray->my += ray->stepy;
				ray->side = 1;
			}
			if (is_wall(data, ray->mx, ray->my) == 0)
				ray->hit = 1;
		}
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
		if (ray->side == 0)
			ray->east_west = (ray->stepx == 1) ? EAST : WEST;
		else
			ray->north_south = (ray->stepy == 1) ? SOUTH : NORTH;
		if (ray->north_south != -1)
		{
			data->current_texture = (ray->north_south == NORTH) ? data->texture->north : data->texture->south;
		}
		if (ray->east_west != -1)
		{
			data->current_texture = (ray->east_west == EAST) ? data->texture->east : data->texture->west;
		}
		draw_texture(data, i);
	}	
}
