/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:31:05 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 17:31:55 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_north(t_cub3d *data, char *path);
int	init_south(t_cub3d *data, char *path);
int	init_west(t_cub3d *data, char *path);
int	init_east(t_cub3d *data, char *path);
int	init_door(t_cub3d *data, char *path);

int	init_north(t_cub3d *data, char *path)
{
	int	w;
	int	h;

	data->texture->north->img_ptr = \
		mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (data->texture->north->img_ptr == NULL)
	{
		ft_putstr_fd("Error: Invalid texture\n", 2);
		free (path);
		return (1);
	}
	data->texture->north->addr = \
	mlx_get_data_addr(data->texture->north->img_ptr, \
	&data->texture->north->bpp, &data->texture->north->line_length, \
	&data->texture->north->endian);
	data->texture->north->width = w;
	data->texture->north->height = h;
	free (path);
	return (0);
}

int	init_south(t_cub3d *data, char *path)
{
	int	w;
	int	h;

	data->texture->south->img_ptr = \
		mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (data->texture->south->img_ptr == NULL)
	{
		free (path);
		return (1);
	}
	data->texture->south->addr = \
	mlx_get_data_addr(data->texture->south->img_ptr, \
	&data->texture->south->bpp, &data->texture->south->line_length, \
	&data->texture->south->endian);
	data->texture->south->width = w;
	data->texture->south->height = h;
	free (path);
	return (0);
}

int	init_west(t_cub3d *data, char *path)
{
	int	w;
	int	h;

	data->texture->west->img_ptr = \
		mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (data->texture->west->img_ptr == NULL)
	{
		free (path);
		return (1);
	}
	data->texture->west->addr = \
	mlx_get_data_addr(data->texture->west->img_ptr, \
	&data->texture->west->bpp, &data->texture->west->line_length, \
	&data->texture->west->endian);
	data->texture->west->width = w;
	data->texture->west->height = h;
	free (path);
	return (0);
}

int	init_east(t_cub3d *data, char *path)
{
	int	w;
	int	h;

	data->texture->east->img_ptr = \
	mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (data->texture->east->img_ptr == NULL)
	{
		free (path);
		return (1);
	}
	data->texture->east->addr = \
	mlx_get_data_addr(data->texture->east->img_ptr, \
	&data->texture->east->bpp, &data->texture->east->line_length, \
	&data->texture->east->endian);
	data->texture->east->width = w;
	data->texture->east->height = h;
	free (path);
	return (0);
}

int	init_door(t_cub3d *data, char *path)
{
	int	w;
	int	h;

	data->texture->door->img_ptr = \
	mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (data->texture->door->img_ptr == NULL)
	{
		free (path);
		return (1);
	}
	data->texture->door->addr = \
	mlx_get_data_addr(data->texture->door->img_ptr, \
	&data->texture->door->bpp, &data->texture->door->line_length, \
	&data->texture->door->endian);
	data->texture->door->width = w;
	data->texture->door->height = h;
	free (path);
	return (0);
}