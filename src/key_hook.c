#include "cub3d.h"

void	free_content(void *content)
{
	t_map_info	*tmp;

	tmp = (t_map_info *)content;
	free(tmp->value);
	free(tmp);
}

void	exit_hook(t_cub3d *data)
{
	ft_lstclear(&data->map_info, free_content);
	mlx_destroy_image(data->mlx, data->img->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->img);
	free_2d(data->map);
	free(data);
	exit(0);
}

int	key_hook(int keycode, t_cub3d *data)
{
	double	old_dirx;
	double	old_planex;
	double	angle;
	double	move_speed;

	angle = 5/180.0 * PI;
	move_speed = 0.2;
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		exit_hook(data);
	if (keycode == 'w')
	{
		if (is_wall(data, (int)(data->player->px + data->player->dirx * move_speed), (int)data->player->py) == 1)
			data->player->px += data->player->dirx * move_speed;
		if (is_wall(data, (int)data->player->px, (int)(data->player->py + data->player->diry * move_speed)) == 1)
			data->player->py += data->player->diry * move_speed;
	}
	if (keycode == 's')
	{
		if (is_wall(data, (int)(data->player->px - data->player->dirx * move_speed), (int)data->player->py) == 1)
			data->player->px -= data->player->dirx * move_speed;
		if (is_wall(data, (int)data->player->px, (int)(data->player->py - data->player->diry * move_speed)) == 1)
			data->player->py -= data->player->diry * move_speed;
	}	
	if (keycode == 'a')
	{
		if (is_wall(data, (int)(data->player->px + data->player->planex * move_speed), (int)data->player->py) == 1)
			data->player->px += data->player->planex * move_speed;
		if (is_wall(data, (int)data->player->px, (int)(data->player->py + data->player->planey * move_speed)) == 1)
			data->player->py += data->player->planey * move_speed;
	}
	if (keycode == 'd')
	{
		if (is_wall(data, (int)(data->player->px - data->player->planex * move_speed), (int)data->player->py) == 1)
			data->player->px -= data->player->planex * move_speed;
		if (is_wall(data, (int)data->player->px, (int)(data->player->py - data->player->planey * move_speed)) == 1)
			data->player->py -= data->player->planey * move_speed;
	}
	if (keycode == 65363)
	{
		old_dirx = data->player->dirx;
		data->player->dirx = data->player->dirx * cos(angle) - data->player->diry * sin(angle);
		data->player->diry = old_dirx * sin(angle) + data->player->diry * cos(angle);
		old_planex = data->player->planex;
		data->player->planex = data->player->planex * cos(angle) - data->player->planey * sin(angle);
		data->player->planey = old_planex * sin(angle) + data->player->planey * cos(angle);
		data->player->pa -= 10;
	}
	if (keycode == 65361)
	{
		old_dirx = data->player->dirx;
		data->player->dirx = data->player->dirx * cos(-angle) - data->player->diry * sin(-angle);
		data->player->diry = old_dirx * sin(-angle) + data->player->diry * cos(-angle);
		old_planex = data->player->planex;
		data->player->planex = data->player->planex * cos(-angle) - data->player->planey * sin(-angle);
		data->player->planey = old_planex * sin(-angle) + data->player->planey * cos(-angle);
		data->player->pa += 10;
	}
	return (0);
}


// w , s, a, d is for moving
// left, right is for rotation