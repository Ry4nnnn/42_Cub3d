/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:36 by tzi-qi            #+#    #+#             */
/*   Updated: 2023/12/09 23:57:12 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #include "keycodes.h"

int		key_hook(int keycode, t_cub3d *data);
void	key_hook_front_back(int keycode, t_cub3d *data);
void	key_hook_left_right(int keycode, t_cub3d *data);
void	key_hook_rotation_left(int keycode, t_cub3d *data);
void	key_hook_rotation_right(int keycode, t_cub3d *data);

/**
 * @brief Handle keyboard input for various actions.
 *
 * This function is the main keyboard input handler that dispatches
 * specific actions based on the pressed key.
 *
 * @param keycode The keycode corresponding to the pressed key.
 * @param data The main data structure for the application.
 * @return Always returns 0.
 */
int	key_hook(int keycode, t_cub3d *data)
{
	if (keycode == KEY_ESC)
		exit_hook(data);
	key_hook_front_back(keycode, data);
	key_hook_left_right(keycode, data);
	key_hook_rotation_left(keycode, data);
	key_hook_rotation_right(keycode, data);
	return (0);
}

/**
 * @brief Move the player forward or backward based on key input.
 *
 * This function handles player movement forward (W) and backward (S).
 *
 * @param keycode The keycode corresponding to the pressed key.
 * @param data The main data structure for the application.
 */
void	key_hook_front_back(int keycode, t_cub3d *data)
{
	double	move_speed;

	move_speed = MOVE_SPEED;
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

/**
 * @brief Move the player left or right based on key input.
 *
 * This function handles player movement left (A) and right (D).
 *
 * @param keycode The keycode corresponding to the pressed key.
 * @param data The main data structure for the application.
 */
void	key_hook_left_right(int keycode, t_cub3d *data)
{
	double	move_speed;

	move_speed = MOVE_SPEED;
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

/**
 * @brief Rotate the player view to the left based on key input.
 *
 * This function handles left rotation of the player's view.
 *
 * @param keycode The keycode corresponding to the pressed key.
 * @param data The main data structure for the application.
 */
void	key_hook_rotation_left(int keycode, t_cub3d *data)
{
	double	old_dirx;
	double	old_planex;
	double	angle;

	angle = ROT_ANGLE * (M_PI / 180);
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

/**
 * @brief Rotate the player view to the right based on key input.
 *
 * This function handles right rotation of the player's view.
 *
 * @param keycode The keycode corresponding to the pressed key.
 * @param data The main data structure for the application.
 */
void	key_hook_rotation_right(int keycode, t_cub3d *data)
{
	double	old_dirx;
	double	old_planex;
	double	angle;

	angle = ROT_ANGLE * (M_PI / 180);
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
}
