/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:22:15 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 14:44:27 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	half_window(t_cub3d *data, int colour1, int colour2);
void	change_colour(t_cub3d *data, t_image *img);
void	drawsquare(t_cub3d	*data, int x, int y, int colour);

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
