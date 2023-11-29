#include "cub3d.h"

static int	handle_middle(t_cub3d *data, int h, int w)
{
	if (data->map->layout[h + 1][w] != ' ' && data->map->layout[h + 1][w] != '1')
		return (1);
	if (data->map->layout[h - 1][w] != ' ' && data->map->layout[h - 1][w] != '1')
		return (1);
	if (data->map->layout[h][w + 1] != ' ' && data->map->layout[h][w + 1] != '1')
		return (1);
	if (data->map->layout[h][w - 1] != ' ' && data->map->layout[h][w - 1] != '1')
		return (1);
	return (0);
}

static int handle_side_wall(t_cub3d *data)
{
	int row;
	int col;
	char *temp;

	row = 0;
	while (data->map->layout[row])
	{
		col = 0;
		while (data->map->layout[row][col])
		{
			if (col != 0 && row != 0 && col != ft_strlen(data->map->layout[row])
				&& row != data->map->height - 1)
			{
				temp = ft_strtrim(data->map->layout[row], " ");
				if (temp[0] != '1' && temp[ft_strlen(temp)] != '1')
					return (1);
				free(temp);
				if (data->map->layout[row][col] == ' ')
					if (handle_middle(data, row, col) == 1)
						return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	handle_wall(t_cub3d *data, char *row, int width)
{
	int i;

	i = 0;
	if (width == 0 || width == data->map->height)
	{
		while (row[i])
		{
			if (row[i] != '1' && row[i] != ' ')
				ft_error(data, "Map is not fully covered by wall\n");
			i++;
		}
	}
	if (handle_side_wall(data) == 1)
		ft_error(data, "map is not fully covered by wall\n");
}