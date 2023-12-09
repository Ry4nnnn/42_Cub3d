/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:25:27 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 22:34:39 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawmap(t_cub3d	*data);
void	draw_base(t_cub3d *data);
void	draw_surrounding_grid(t_cub3d *data);
void	draw_middle_grid(t_cub3d *data);

/**
 * @brief Draw the map on the screen.
 *
 * This function draws the map on the screen. It consists of a grid
 * representing the walls and other elements in different colors.
 *
 * @param data The main data structure for the application.
 */
void	drawmap(t_cub3d *data)
{
	draw_base(data);
	draw_surrounding_grid(data);
	draw_middle_grid(data);
}

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
