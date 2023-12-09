/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:22:15 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:42:09 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	half_window(t_cub3d *data, int colour1, int colour2);
void	change_colour(t_cub3d *data, t_image *img);
void	drawsquare(t_cub3d	*data, int x, int y, int colour);
int		is_wall(t_cub3d *data, int x, int y);

/**
 * @brief Draw the upper half of the window with two different colors.
 *
 * This function divides the window into two halves and fills the upper half
 * with the specified colors.
 *
 * @param data The main data structure for the application.
 * @param colour1 The color for the top half.
 * @param colour2 The color for the bottom half.
 */
void	half_window(t_cub3d *data, int colour1, int colour2)
{
	t_image	*img_info;

	img_info = ft_calloc(1, sizeof(t_image));
	img_info->start_x = 0;
	img_info->start_y = 0;
	img_info->dest_x = SIZE_X;
	img_info->dest_y = SIZE_Y / 2;
	img_info->colour = colour1;
	change_colour(data, img_info);
	img_info->start_x = 0;
	img_info->start_y = SIZE_Y / 2;
	img_info->dest_x = SIZE_X;
	img_info->dest_y = SIZE_Y;
	img_info->colour = colour2;
	change_colour(data, img_info);
}

/**
 * @brief Change the color of a specified region in the window.
 *
 * This function changes the color of a specified rectangular region 
 * in the window.
 *
 * @param data The main data structure for the application.
 * @param img The image information containing parameters for the region.
 */
void	change_colour(t_cub3d *data, t_image *img)
{
	int	i;
	int	j;

	j = img->start_y - 1;
	while (++j <= img->dest_y)
	{
		i = img->start_x - 1;
		while (++i <= img->dest_x)
			my_mlx_pixel_put(data, i, j, img->colour);
	}
}

/**
 * @brief Draw a square with a specified color.
 *
 * This function draws a square in the window with a specified color.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the square.
 * @param y The y-coordinate of the square.
 * @param colour The color of the square.
 */
void	drawsquare(t_cub3d	*data, int x, int y, int colour)
{
	int	i;
	int	j;

	j = y - 1;
	while (++j <= y + 20)
	{
		i = x - 1;
		while (++i <= x + 20)
			my_mlx_pixel_put(data, i, j, colour);
	}
}

/**
 * @brief Check if a given position is a wall or other element.
 *
 * This function checks if a given position in the map is a wall or another
 * type of element. It returns different values based on the content of the
 * map at the specified position.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the position.
 * @param y The y-coordinate of the position.
 * @return 0 if the position is wall, 2 if the position is either one of 
 * he NEWS walls, 3 if the position is an empty space, 4 for spaces,
 * 1 for other cases
 */
int	is_wall(t_cub3d *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->texture->width \
		|| y >= data->texture->height)
		return (1);
	if (data->texture->map[y][x] == '1')
		return (0);
	else if (data->texture->map[y][x] == 'N' \
			|| data->texture->map[y][x] == 'S' \
			|| data->texture->map[y][x] == 'E' \
			|| data->texture->map[y][x] == 'W')
		return (2);
	else if (data->texture->map[y][x] == '0')
		return (3);
	else if (data->texture->map[y][x] == ' ')
		return (4);
	else
		return (1);
}
