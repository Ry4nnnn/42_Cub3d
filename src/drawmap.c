/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:25:27 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:43:45 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawmap(t_cub3d	*data);
void	draw_base(t_cub3d *data);
void	draw_surrounding_grid(t_cub3d *data);
void	draw_middle_grid(t_cub3d *data);

/**
 * @brief Draw the entire map.
 *
 * This function coordinates the drawing of the base, 
 * surrounding grid, and middle grid.
 *
 * @param data The main data structure for the application.
 */
void	drawmap(t_cub3d *data)
{
	draw_base(data);
	draw_surrounding_grid(data);
	draw_middle_grid(data);
}

/**
 * @brief Draw the base of the map.
 *
 * This function fills the entire map area with a base color.
 *
 * @param data The main data structure for the application.
 */
void	draw_base(t_cub3d *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < 198)
	{
		i = -1;
		while (++i < 198)
			my_mlx_pixel_put(data, i, j, 0x007DC3E9);
	}
}

/**
 * @brief Draw the surrounding grid of the player's position.
 *
 * This function draws a grid around the player's position, with 
 * different colors based on whether the grid cell is open (white), 
 * a wall (dark gray), or other elements.
 *
 * @param data The main data structure for the application.
 */
void	draw_surrounding_grid(t_cub3d *data)
{
	int	i;
	int	j;
	int	r;

	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			r = is_wall(data, (int)(data->player->px) - 4 + i, \
				(int)(data->player->py) - 4 + j);
			if (r == 0)
				drawsquare(data, i * 22, j * 22, 0x00FFFFFF);
			else if (r == 2 || r == 3)
				drawsquare(data, i * 22, j * 22, 0x00111111);
			else
				continue ;
		}
	}
}

/**
 * @brief Draw the middle grid of the player's direction.
 *
 * This function draws a grid in the direction the player is facing,
 * with a special color.
 *
 * @param data The main data structure for the application.
 */
void	draw_middle_grid(t_cub3d *data)
{
	int	i;
	int	j;
	int	r;

	drawsquare(data, 88, 88, 0x00E97D7D);
	r = -1;
	while (++r < 25)
	{
		i = r * (data->player->dirx);
		j = r * (data->player->diry);
		my_mlx_pixel_put(data, 88 + 10 + i, 88 + 10 + j, 0x00E97D7D);
		my_mlx_pixel_put(data, 88 + 11 + i, 88 + 11 + j, 0x00E97D7D);
		my_mlx_pixel_put(data, 88 + 12 + i, 88 + 12 + j, 0x00E97D7D);
	}
}
