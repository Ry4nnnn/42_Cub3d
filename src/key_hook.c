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

	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		exit_hook(data);
	if (keycode == 'w')
	{
		printf("before w px: %f, py: %f\n", data->player->px, data->player->py);
		// if (data->map[(int)(data->player->px + data->player->dirx * 0.1)][(int)data->player->py] != '1')
		data->player->px += data->player->dirx * 10;
		// if (data->map[(int)(data->player->px)][(int)(data->player->py + data->player->diry * 0.1)] == '1')
		data->player->py += data->player->diry * 10;
		printf("after w px: %f, py: %f\n", data->player->px, data->player->py);
	}
	if (keycode == 's')
	{
		// if (data->map[(int)(data->player->px + data->player->dirx * 0.1)][(int)data->player->py] != '1')
			data->player->px -= data->player->dirx * 10;
		// if (data->map[(int)(data->player->px)][(int)(data->player->py + data->player->diry * 0.1)] == '1')
			data->player->py -= data->player->diry * 10;
	}	
	if (keycode == 'a')
	{
		data->player->px += data->player->planex * 10;
		data->player->py += data->player->planey * 10;
	}
	if (keycode == 'd')
	{
		data->player->px -= data->player->planex * 10;
		data->player->py -= data->player->planey * 10;
	}
	if (keycode == 65363)
	{
		old_dirx = data->player->dirx;
		data->player->dirx = data->player->dirx * cos(0.2) - data->player->diry * sin(0.2);
		data->player->diry = old_dirx * sin(0.2) + data->player->diry * cos(0.2);
		old_planex = data->player->planex;
		data->player->planex = data->player->planex * cos(0.2) - data->player->planey * sin(0.2);
		data->player->planey = old_planex * sin(0.2) + data->player->planey * cos(0.2);
	}
	if (keycode == 65361)
	{
		old_dirx = data->player->dirx;
		data->player->dirx = data->player->dirx * cos(-0.2) - data->player->diry * sin(-0.2);
		data->player->diry = old_dirx * sin(-0.2) + data->player->diry * cos(-0.2);
		old_planex = data->player->planex;
		data->player->planex = data->player->planex * cos(-0.2) - data->player->planey * sin(-0.2);
		data->player->planey = old_planex * sin(-0.2) + data->player->planey * cos(-0.2);
	}
	return (0);
}


// w , s, a, d is for moving
// left, right is for rotation