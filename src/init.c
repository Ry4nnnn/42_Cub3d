/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:00:06 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:55:48 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_cub3d *data);

/**
 * @brief Initialize the main data structure.
 *
 * This function initializes the main data structure for the application,
 * including memory allocation for textures, the player, and the ray.
 *
 * @param data The main data structure for the application.
 */
void	init_data(t_cub3d *data)
{
	data->mlx = mlx_init();
	data->texture = ft_calloc(1, sizeof(t_texture));
	data->texture->north = ft_calloc(1, sizeof(t_img_data));
	data->texture->south = ft_calloc(1, sizeof(t_img_data));
	data->texture->west = ft_calloc(1, sizeof(t_img_data));
	data->texture->east = ft_calloc(1, sizeof(t_img_data));
	data->texture->door = ft_calloc(1, sizeof(t_img_data));
	data->texture->map = NULL;
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->t = 0;
	data->player->old_t = 0;
	data->ray = ft_calloc(1, sizeof(t_ray));
	data->ray->north_south = -1;
	data->ray->east_west = -1;
}
