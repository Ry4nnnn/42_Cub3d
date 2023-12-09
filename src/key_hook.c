/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:36 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 17:51:39 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #include "keycodes.h"

int		exit_hook(t_cub3d *data);
int		key_hook(int keycode, t_cub3d *data);
void	key_hook_front_back(int keycode, t_cub3d *data);
void	key_hook_left_right(int keycode, t_cub3d *data);
void	key_hook_rotation(int keycode, t_cub3d *data);

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
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->img);
	free(data->ray);
	free(data->player);
	free_2d(data->texture->map);
	free(data);
	exit(0);
}

/**
 * @brief Handle keyboard input events.
 *
 * This function is responsible for handling keyboard input events,
 * such as moving the player or exiting the program.
 *
 * @param keycode The keycode representing the pressed key.
 * @param data The main data structure for the application.
 * @return Always returns 0.
 */
int	key_hook(int keycode, t_cub3d *data)
{
	if (keycode == KEY_ESC)
		exit_hook(data);
	key_hook_front_back(keycode, data);
	key_hook_left_right(keycode, data);
	key_hook_rotation(keycode, data);
	return (0);
}

void	key_hook_front_back(int keycode, t_cub3d *data)
{
	double	move_speed;

	move_speed = 0.1;
	if (keycode == KEY_W)
	{
		if (is_wall(data, (int)(data->player->px + \
			data->player->dirx * move_speed), (int)data->player->py) != 0)
			data->player->px += data->player->dirx * move_speed;
		if (is_wall(data, (int)data->player->px, \
			(int)(data->player->py + data->player->diry * move_speed)) != 0)
			data->player->py += data->player->diry * move_speed;
	}
	if (keycode == KEY_S)
	{
		if (is_wall(data, (int)(data->player->px - \
			data->player->dirx * move_speed), (int)data->player->py) != 0)
			data->player->px -= data->player->dirx * move_speed;
		if (is_wall(data, (int)data->player->px, \
			(int)(data->player->py - data->player->diry * move_speed)) != 0)
			data->player->py -= data->player->diry * move_speed;
	}
}

void	key_hook_left_right(int keycode, t_cub3d *data)
{
	double	move_speed;

	move_speed = 0.1;
	if (keycode == KEY_A)
	{
		if (is_wall(data, (int)(data->player->px + \
			data->player->planex * move_speed), (int)data->player->py) != 0)
			data->player->px += data->player->planex * move_speed;
		if (is_wall(data, (int)data->player->px, \
			(int)(data->player->py + data->player->planey * move_speed)) != 0)
			data->player->py += data->player->planey * move_speed;
	}
	if (keycode == KEY_D)
	{
		if (is_wall(data, (int)(data->player->px - \
			data->player->planex * move_speed), (int)data->player->py) != 0)
			data->player->px -= data->player->planex * move_speed;
		if (is_wall(data, (int)data->player->px, \
			(int)(data->player->py - data->player->planey * move_speed)) != 0)
			data->player->py -= data->player->planey * move_speed;
	}
}

void	key_hook_rotation(int keycode, t_cub3d *data)
{
	double	old_dirx;
	double	old_planex;
	double	angle;

	angle = 5 / 180.0 * PI;
	if (keycode == KEY_RIGHT)
	{
		old_dirx = data->player->dirx;
		data->player->dirx = data->player->dirx * cos(angle) \
							- data->player->diry * sin(angle);
		data->player->diry = old_dirx * sin(angle) \
							+ data->player->diry * cos(angle);
		old_planex = data->player->planex;
		data->player->planex = data->player->planex * cos(angle) \
								- data->player->planey * sin(angle);
		data->player->planey = old_planex * sin(angle) \
							+ data->player->planey * cos(angle);
	}
	if (keycode == KEY_LEFT)
	{
		old_dirx = data->player->dirx;
		data->player->dirx = data->player->dirx * cos(-angle) \
							- data->player->diry * sin(-angle);
		data->player->diry = old_dirx * sin(-angle) \
							+ data->player->diry * cos(-angle);
		old_planex = data->player->planex;
		data->player->planex = data->player->planex * cos(-angle) \
								- data->player->planey * sin(-angle);
		data->player->planey = old_planex * sin(-angle) \
							+ data->player->planey * cos(-angle);
	}
}
