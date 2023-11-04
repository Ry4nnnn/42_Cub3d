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
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		exit_hook(data);
	if (keycode == 'w')
		data->py -= 10;
	if (keycode == 's')
		data->py += 10;
	if (keycode == 'a')
		data->px -= 10;
	if (keycode == 'd')
		data->px += 10;
	return (0);
}
