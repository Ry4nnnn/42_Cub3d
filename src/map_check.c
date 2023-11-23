#include "cub3d.h"

int	init_textures(t_cub3d *data, char *str)
{
	int w;
	int h;

	w = 0;
	h = 0;
	if (!ft_strncmp(str, "NO ", 3))
		data->texture.north = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(str, '.'), &w, &h);
	else if (!ft_strncmp(str, "SO ", 3))
		data->texture.south = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(str, '.'), &w, &h);
	else if (!ft_strncmp(str, "WE ", 3))
		data->texture.west = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(str, '.'), &w, &h);
	else if (!ft_strncmp(str, "EA ", 3))
		data->texture.east = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(str, '.'), &w, &h);
	else if (!ft_strncmp(str, "DO ", 3))
		data->texture.door = mlx_xpm_file_to_image(data->mlx,
			ft_strchr(str, '.'), &w, &h);
	data->texture.width = w;
	data->texture.height = h;
	return (0);
}

int init_fc_color(t_cub3d *data, char *str)
{
	int i;

	i = 0;
	if (!ft_strncmp(str, "F ", 2))
	{
		data->texture.floor[0] = ft_atoi(&str[2]);
		data->texture.floor[1] = ft_atoi(ft_strchr(&str[2], ',') + 1);
		data->texture.floor[2] = ft_atoi(ft_strchr(ft_strchr(&str[2], ',') + 1, ',') + 1);
		while (data->texture.floor[i])
		{
			// printf ("floor %i\n", data->texture.floor[i]);
			if (data->texture.floor[i] < 0 || data->texture.floor[i] > 255)
			{
				printf ("invalid floor color\n");
				exit (1);
			}
			i++;
		}
		i = 0;
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		data->texture.ceiling[0] = ft_atoi(&str[2]);
		data->texture.ceiling[1] = ft_atoi(ft_strchr(&str[2], ',') + 1);
		data->texture.ceiling[2] = ft_atoi(ft_strchr(ft_strchr(&str[2], ',') + 1, ',') + 1);
		while (data->texture.ceiling[i])
		{
			// printf ("ceiling %i\n", data->texture.ceiling[i]);
			if (data->texture.ceiling[i] < 0 || data->texture.ceiling[i] > 255)
			{
				printf ("invalid ceiling color\n");
				exit (1);
			}
			i++;
		}
	}
	return (0);
}

void init_map_layout(t_cub3d *data, char **array, int i)
{
		int	j;

		j = i;
		while (array[j])
			j++;
		data->map_y = j - i;
		data->map = malloc(sizeof(char **) * (j - i + 1));
		j = -1;
		while (array[i])
			data->map[++j] = ft_strdup(array[i++]);
		data->map[++j] = NULL;
		// ft_strlcat(data->map[0], "\r\0", ft_strlen(data->map[0]) + 2);
}

void	handle_wall_diagonal(t_cub3d *data, int y, int x)
{
	if (data->map[y + 1] && data->map[y][x + 1] && data->map[y + 1][x + 1] && x < ft_strlen(data->map[y + 1]))
		if (data->map[y + 1][x + 1] != '1' && data->map[y + 1][x + 1] != ' ' && data->map[y + 1][x + 1] != '\r')
			ft_error(data, "Map not closed diagonally");
	if (data->map[y + 1] && data->map[y + 1][x - 1] && x - 1 > 0 && x < ft_strlen(data->map[y + 1]))
		if (data->map[y + 1][x - 1] != '1' && data->map[y + 1][x - 1] != ' ' && data->map[y + 1][x - 1] != '\r')
			ft_error(data, "Map not closed diagonally");
	if (y - 1 > 0 && data->map[y - 1][x + 1] && x < ft_strlen(data->map[y - 1])) if (data->map[y - 1][x + 1] != '1' && data->map[y - 1][x + 1] != ' ' && data->map[y - 1][x + 1] != '\r')
			ft_error(data, "Map not closed diagonally");
	if (y - 1 > 0 && x - 1 > 0 && x < ft_strlen(data->map[y - 1]) && data->map[y - 1][x - 1])
		if (data->map[y - 1][x - 1] != '1' && data->map[y - 1][x - 1] != ' ' && data->map[y - 1][x - 1] != '\r')
			ft_error(data, "Map not closed diagonally");
}

void	handle_wall_closure(t_cub3d *data, int x, int y)
{
	if (data->map[y][x + 1])
		if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ' && data->map[y][x + 1] != '\r')
			ft_error(data, "Map not closed");
	if (data->map[y + 1] && data->map[y + 1][x] && x < ft_strlen(data->map[y + 1]))
		if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ' && data->map[y + 1][x] != '\r')
			
	if (x - 1 > 0)
		if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ' && data->map[y][x - 1] != '\r')
			ft_error(data, "Map not closed");
	if (y - 1 > 0 && data->map[y - 1][x] && x < ft_strlen(data->map[y - 1]))
		if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ' && data->map[y - 1][x] != '\r')
			ft_error(data, "Map not closed");
	handle_wall_diagonal(data, y, x);
}

void	handle_pspawn(t_cub3d *data, int y, int x)
{
	if (data->player.spawn_dir != 0
		&& (data->map[y][x] == 'N' || data->map[y][x] == 'S'
		|| data->map[y][x] == 'E' || data->map[y][x] == 'W'))
		ft_error(data, "Multiple player found");
	else if (data->player.spawn_dir == 0
		&& (data->map[y][x] == 'N' || data->map[y][x] == 'S'
		|| data->map[y][x] == 'E' || data->map[y][x] == 'W'))
	{
		data->player.spawn_dir = data->map[y][x];
		data->player.pos_x = x;
		data->player.pos_y = y;
		// data->map[y][x] = '0'; // to allow player to stand/spawn on the floor
	}
	else if (data->map[y][x] != '0' && data->map[y][x] != '1' && data->map[y][x] != '2'
		&& data->map[y][x] != 'N' && data->map[y][x] != 'S' && data->map[y][x] != '\r'
		&& data->map[y][x] != 'E' && data->map[y][x] != 'W' && data->map[y][x] != ' ')
	{
		printf("%c\n", data->map[y][x]);
		ft_error(data, "Invalid character in map");
	}
}

void	handle_walls(t_cub3d *data, int y, int x)
{
	x = -1;
	while (data->map[0][++x])
	{
		if (data->map[0][x] != '1' && data->map[0][x] != ' ' && data->map[0][x] != '\r')
			ft_error(data, "top of the map is not closed");
	}
	x = -1;
	while (data->map[data->map_y - 1][++x])
	{
		if (data->map[data->map_y - 1][x] != '1'
			&& data->map[data->map_y - 1][x] != ' '
			&& data->map[data->map_y - 1][x] != '\r')
			ft_error(data, "bottom of the map is not closed");
	}
	y = -1;
	while (data->map[++y] && data->map[y][0])
	{
		if (data->map[y][0] != '1' && data->map[y][0] != ' ' && data->map[y][0] != '\r')
			ft_error(data, "left side of the map is not closed");
	}
}

void	handle_map(t_cub3d *data)
{
	int y;
	int x;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		if (ft_strncmp(data->map[y], "\r", 1) == 0)
			ft_error(data, "empty line found in map.");
		while (data->map[y][++x])
		{
			if (data->map[y][x] == ' ' || data->map[y][x] == '\r')
				handle_wall_closure(data, y, x);
			handle_pspawn(data, y, x);
		}
		handle_walls(data, y, x);
	}
}

// static void	show_map_info(t_cub3d *data)
// {
// 	printf ("MAP\n");
// 	for (int i = 0; data->map[i]; i++)
// 		printf ("%s\n", data->map[i]);
// }

int	init_file_data(t_cub3d *data, char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		init_textures(data, array[i]);
		init_fc_color(data, array[i]);
		if (ft_strncmp(array[i], " ", 1) == 0 || ft_strncmp(array[i], "1", 1) == 0)
		{
			init_map_layout(data, array, i);
			handle_map(data);
			break;
		}
		else
			ft_error(data, "error\n");
		i++;
	}
	// show_map_info(data);
	return (0);
}

int	map_check(t_cub3d *data, char **array)
{
    if(init_file_data(data, array) == 1)
		return (1);
	return (0);
}
