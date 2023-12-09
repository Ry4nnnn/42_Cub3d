/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:54:20 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:44:47 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawray(t_cub3d *data);
void	init_ray(t_cub3d *data, t_ray *ray, int x, int w);
void	wall_hit(t_cub3d *data, t_ray *ray);

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
		wall_hit(data, ray);
		assign_wall_height(data, ray);
		assign_direction(ray);
		assign_current_texture(data, ray);
		draw_texture(data, i);
	}	
}

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
	assign_x_y_offset(data, ray);
}

/**
 * @brief Determine the point of intersection with a wall.
 *
 * This function updates the ray's position until it intersects with a wall.
 *
 * @param data The main data structure for the application.
 * @param ray The ray structure.
 */
void	wall_hit(t_cub3d *data, t_ray *ray)
{
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
}
