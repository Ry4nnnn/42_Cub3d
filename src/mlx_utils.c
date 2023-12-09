/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:19:56 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 15:19:57 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color);

/**
 * @brief Set the color of a pixel in the image.
 *
 * This function sets the color of a pixel at the specified coordinates (x, y)
 * in the image associated with the t_cub3d structure.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color to set the pixel to.
 */
void	my_mlx_pixel_put(t_cub3d *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y)
		return ;
	dst = data->img->addr + (y * data->img->line_length \
		+ x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}
