/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:35:51 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 17:40:50 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_data(t_cub3d *data, int x, int y, int dir);
void	init_player_data_north_south(t_cub3d *data, int dir);
void	init_player_data_east_west(t_cub3d *data, int dir);

/**
 * @brief Initialize player data.
 *
 * This function initializes player data based on a given position and
 * direction.
 *
 * @param data The main data structure for the application.
 * @param x The x-coordinate of the player.
 * @param y The y-coordinate of the player.
 * @param dir The direction of the player.
 */
void	init_player_data(t_cub3d *data, int x, int y, int dir)
{
	data->player->px = x + 0.2;
	data->player->py = y + 0.2;
	init_player_data_north_south(data, dir);
	init_player_data_east_west(data, dir);
}

/**
 * @brief Initialize player data for north and south directions.
 *
 * This function initializes player data based on a given direction.
 *
 * @param data The main data structure for the application.
 * @param dir The direction of the player.
 */
void	init_player_data_north_south(t_cub3d *data, int dir)
{
	if (dir == NORTH)
	{
		data->player->dirx = 0;
		data->player->diry = -1;
		data->player->planex = -0.45;
		data->player->planey = 0;
	}
	else if (dir == SOUTH)
	{
		data->player->dirx = 0;
		data->player->diry = 1;
		data->player->planex = 0.45;
		data->player->planey = 0;
	}
}

/**
 * @brief Initialize player data for east and west directions.
 *
 * This function initializes player data based on a given direction.
 *
 * @param data The main data structure for the application.
 * @param dir The direction of the player.
 */
void	init_player_data_east_west(t_cub3d *data, int dir)
{
	if (dir == EAST)
	{
		data->player->dirx = 1;
		data->player->diry = 0;
		data->player->planex = 0;
		data->player->planey = -0.45;
	}
	else if (dir == WEST)
	{
		data->player->dirx = -1;
		data->player->diry = 0;
		data->player->planex = 0;
		data->player->planey = 0.45;
	}
}