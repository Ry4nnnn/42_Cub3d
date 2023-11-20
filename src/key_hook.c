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

	angle = 10/180.0 * PI;
	if (keycode == 65307)
		exit_hook(data);
	if (keycode == 'w')
	{
		if (data->map[(int)data->player->py][(int)(data->player->px + data->player->dirx * 0.1)] != '1')
			data->player->px += data->player->dirx * 0.1;
		if (data->map[(int)(data->player->py + data->player->diry * 0.1)][(int)(data->player->px)] != '1')
			data->player->py += data->player->diry * 0.1;
	}
	if (keycode == 's')
	{
		if (data->map[(int)data->player->py][(int)(data->player->px - data->player->dirx * 0.1)] != '1')
			data->player->px -= data->player->dirx * 0.1;
		if (data->map[(int)(data->player->py - data->player->diry * 0.1)][(int)(data->player->px)] != '1')
			data->player->py -= data->player->diry * 0.1;
	}	
	if (keycode == 'a')
	{
		if (data->map[(int)data->player->py][(int)(data->player->px + data->player->planex * 0.1)] != '1')
			data->player->px += data->player->planex * 0.1;
		if (data->map[(int)(data->player->py + data->player->planey * 0.1)][(int)(data->player->px)] != '1')
			data->player->py += data->player->planey * 0.1;
	}
	if (keycode == 'd')
	{
		if (data->map[(int)data->player->py][(int)(data->player->px - data->player->planex * 0.1)] != '1')
			data->player->px -= data->player->planex * 0.1;
		if (data->map[(int)(data->player->py - data->player->planey * 0.1)][(int)(data->player->px)] != '1')
			data->player->py -= data->player->planey * 0.1;
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