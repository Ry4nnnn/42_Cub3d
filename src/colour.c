#include "cub3d.h"

void    half_window(t_cub3d *data, int colour1, int colour2)
{
	t_image	*img_info;

    img_info = ft_calloc(1, sizeof(t_image));
	img_info->start_x = 0;
	img_info->start_y = 0;
	img_info->dest_x = SIZE_X;
	img_info->dest_y = SIZE_Y / 2;
	img_info->colour = colour1;
	change_colour(data, img_info);
	img_info->start_x = 0;
	img_info->start_y = SIZE_Y / 2;
	img_info->dest_x = SIZE_X;
	img_info->dest_y = SIZE_Y;
	img_info->colour = colour2;
	change_colour(data, img_info);
}

void    change_colour(t_cub3d *data, t_image *img)
{
    int i;
    int j;

    j = img->start_y - 1;
    while (++j <= img->dest_y)
    {
        i = img->start_x - 1;
        while (++i <= img->dest_x)
           my_mlx_pixel_put(data, i, j, img->colour);
    }
}

void    drawPlayer(t_cub3d	*data)
{
    int i;
    int j;

    j = data->py - 1;
    while (++j <= data->py + 8)
    {
        i = data->px - 1;
        while (++i <= data->px + 8)
            my_mlx_pixel_put(data, i, j, 0x00B9C781);
    }
}

void	drawSquare(t_cub3d	*data, int x, int y, int colour)
{
	int	i;
	int	j;

	j = y - 1;
	while (++j <= y + 20)
	{
		i = x - 1;
		while (++i <= x + 20)
			my_mlx_pixel_put(data, i, j, colour);
	}
}

void    drawMap(t_cub3d	*data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '1')
				drawSquare(data, i * 22, j * 22, 0x00FFFFFF);
			else if (map[j][i] == '0')
				drawSquare(data, i * 22, j * 22, 0x00111111);
		}
	}
	
}