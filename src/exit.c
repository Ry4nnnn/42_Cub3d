/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:00:00 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/11 21:15:50 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_exit(t_cub3d *data);
int	exit_hook(t_cub3d *data);

/**
 * @brief Free allocated memory and exit the program in case of an error.
 *
 * This function frees the allocated memory for textures, player, 
 * ray, map, and the main data structure. It then exits the program with 
 * an error status.
 *
 * @param data The main data structure for the application.
 */
int	error_exit(t_cub3d *data)
{
	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture->door);
	free(data->texture);
	free(data->player);
	free(data->ray);
	if (data->texture->map != NULL)
		free_2d(data->texture->map);
	free(data);
	exit(1);
}

/**
 * @brief Clean-up and exit the program.
 *
 * This function is called when the user initiates an exit action.
 * It performs cleanup by destroying the image, window, 
 * display, and freeing allocated memory.
 *
 * @param data The main data structure for the application.
 */
int	exit_hook(t_cub3d *data)
{
	mlx_destroy_image(data->mlx, data->texture->north->img_ptr);
	mlx_destroy_image(data->mlx, data->texture->south->img_ptr);
	mlx_destroy_image(data->mlx, data->texture->east->img_ptr);
	mlx_destroy_image(data->mlx, data->texture->west->img_ptr);
	mlx_destroy_image(data->mlx, data->texture->door->img_ptr);
	free(data->texture->north);
	free(data->texture->south);
	free(data->texture->east);
	free(data->texture->west);
	free(data->texture->door);
	free_2d(data->texture->map);
	free(data->texture);
	free(data->ray);
	free(data->player);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->img);
	free(data->img);
	free(data);
	system("leaks cub3d");
	exit(0);
}
