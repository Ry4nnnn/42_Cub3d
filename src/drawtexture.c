/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawtexture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:55:28 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:49:04 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_texture(t_cub3d *data, int x);
static double	calculate_wall_hit(t_cub3d *data);

/**
 * @brief Draw a texture on the screen.
 *
 * This function draws a texture on the screen based on the ray parameters.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the screen column.
 */
void	draw_texture(t_cub3d *data, int x)
{
	t_coord	wall;
	t_coord	draw;
	int		wall_index;
	double	wall_hit;
	char	*dest;

	wall_hit = calculate_wall_hit(data);
	draw.x = x;
	draw.y = data->ray->drawstart - 1;
	while (++draw.y <= data->ray->drawend)
	{
		wall.x = (int)(wall_hit * data->current_texture->width);
		wall.y = (int)(((double)((draw.y - data->ray->drawstart)) / \
					(double)data->ray->lineheight) \
					* data->current_texture->width);
		wall_index = wall.x * (data->current_texture->bpp / 8) \
					+ wall.y * data->current_texture->line_length;
		dest = data->current_texture->addr + wall_index;
		my_mlx_pixel_put(data, SIZE_X - draw.x, draw.y, *(unsigned int *)dest);
		(void)dest;
	}
}

/**
 * @brief Calculate the position of the wall hit for texture mapping.
 *
 * This function calculates the position of the wall hit for texture mapping.
 *
 * @param data The main data structure for the application.
 * @return The calculated wall hit position.
 */
static double	calculate_wall_hit(t_cub3d *data)
{
	double	wall_hit;

	if (data->ray->side == 0)
	{
		wall_hit = (data->player->py + \
					data->ray->perpwalldist * (data->ray->raydiry));
	}
	else
	{
		wall_hit = (data->player->px + \
					data->ray->perpwalldist * (data->ray->raydirx));
	}
	wall_hit -= floor(wall_hit);
	if (data->ray->east_west == WEST || data->ray->north_south == SOUTH)
		wall_hit = 1 - wall_hit;
	return (wall_hit);
}
