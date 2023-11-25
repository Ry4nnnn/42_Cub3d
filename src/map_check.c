#include "cub3d.h"

int	init_textures(t_cub3d *data, char *str)
{
	int		w;
	int		h;
	char	*path;

	if (ft_strchr(str, '.') == NULL)
		return (1);
	path = ft_strjoin("./images/", ft_strchr(str, '.') + 2);
	if (!ft_strncmp(str, "NO ", 3))
	{
		data->texture->north->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
		if (data->texture->north->img_ptr == NULL)
		{
			free (path);
			return (1);
		}
		data->texture->north->addr = mlx_get_data_addr(data->texture->north->img_ptr, &data->texture->north->bpp, &data->texture->north->line_length, &data->texture->north->endian);
		data->texture->north->width = w;
		data->texture->north->height = h;
		printf ("north %i %i\n", data->texture->north->width, data->texture->north->height);
	}
	else if (!ft_strncmp(str, "SO ", 3))
	{
		data->texture->south->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
		if (data->texture->south->img_ptr == NULL)
		{
			free (path);
			return (1);
		}
		data->texture->south->addr = mlx_get_data_addr(data->texture->south->img_ptr, &data->texture->south->bpp, &data->texture->south->line_length, &data->texture->south->endian);
		data->texture->south->width = w;
		data->texture->south->height = h;
		printf ("south %i %i\n", data->texture->south->width, data->texture->south->height);
	}
	else if (!ft_strncmp(str, "WE ", 3))
	{
		data->texture->west->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
		if (data->texture->west->img_ptr == NULL)
		{
			free (path);
			return (1);
		}
		data->texture->west->addr = mlx_get_data_addr(data->texture->west->img_ptr, &data->texture->west->bpp, &data->texture->west->line_length, &data->texture->west->endian);
		data->texture->west->width = w;
		data->texture->west->height = h;
		printf ("west %i %i\n", data->texture->west->width, data->texture->west->height);
	}
	else if (!ft_strncmp(str, "EA ", 3))
	{
		data->texture->east->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
		if (data->texture->east->img_ptr == NULL)
		{
			free (path);
			return (1);
		}
		data->texture->east->addr = mlx_get_data_addr(data->texture->east->img_ptr, &data->texture->east->bpp, &data->texture->east->line_length, &data->texture->east->endian);
		data->texture->east->width = w;
		data->texture->east->height = h;
		printf ("east %i %i\n", data->texture->east->width, data->texture->east->height);
	}
	else if (!ft_strncmp(str, "DO ", 3))
	{
		data->texture->door->img_ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
		if (data->texture->door->img_ptr == NULL)
		{
			free (path);
			return (1);
		}
		data->texture->door->addr = mlx_get_data_addr(data->texture->door->img_ptr, &data->texture->door->bpp, &data->texture->door->line_length, &data->texture->door->endian);
		data->texture->door->width = w;
		data->texture->door->height = h;
		printf ("door %i %i\n", data->texture->door->width, data->texture->door->height);
	}
	free (path);
	return (0);
}

int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int init_fc_color(t_cub3d *data, char *str)
{
	int i;
	char **array;
	char **num;

	i = -1;
	array = ft_split(str, ' ');
	num = ft_split(array[1], ',');
	if (!ft_strncmp(str, "F ", 2))
	{
		i = -1;
		while (num[++i])
		{
			if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			{
				free_2d(array);
				free_2d(num);
				return (1);
			}
		}
		data->texture->floor = rgb_to_hex(ft_atoi(num[0]), ft_atoi(num[1]), ft_atoi(num[2]));
		printf ("floor %i\n", data->texture->floor);
	}
	else if (!ft_strncmp(str, "C ", 2))
	{
		i = -1;
		while (num[++i])
		{
			if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			{
				free_2d(array);
				free_2d(num);
				return (1);
			}
		}
		data->texture->ceiling = rgb_to_hex(ft_atoi(num[0]), ft_atoi(num[1]), ft_atoi(num[2]));
		printf ("ceiling %i\n", data->texture->ceiling);
	}
	free_2d(array);
	free_2d(num);
	return (0);
}

// void init_map_layout(t_cub3d *data, char **array, int i)
// {
// 		int	j;

// 		j = i;
// 		while (array[j])
// 			j++;
// 		data->map_y = j - i;
// 		data->map = malloc(sizeof(char **) * (j - i + 1));
// 		j = -1;
// 		while (array[i])
// 			data->map[++j] = ft_strdup(array[i++]);
// 		data->map[++j] = NULL;
// 		// ft_strlcat(data->map[0], "\r\0", ft_strlen(data->map[0]) + 2);
// }

// void	handle_wall_diagonal(t_cub3d *data, int y, int x)
// {
// 	if (data->map[y + 1] && data->map[y][x + 1] && data->map[y + 1][x + 1] && x < ft_strlen(data->map[y + 1]))
// 		if (data->map[y + 1][x + 1] != '1' && data->map[y + 1][x + 1] != ' ' && data->map[y + 1][x + 1] != '\r')
// 			ft_error(data, "Map not closed diagonally");
// 	if (data->map[y + 1] && data->map[y + 1][x - 1] && x - 1 > 0 && x < ft_strlen(data->map[y + 1]))
// 		if (data->map[y + 1][x - 1] != '1' && data->map[y + 1][x - 1] != ' ' && data->map[y + 1][x - 1] != '\r')
// 			ft_error(data, "Map not closed diagonally");
// 	if (y - 1 > 0 && data->map[y - 1][x + 1] && x < ft_strlen(data->map[y - 1])) if (data->map[y - 1][x + 1] != '1' && data->map[y - 1][x + 1] != ' ' && data->map[y - 1][x + 1] != '\r')
// 			ft_error(data, "Map not closed diagonally");
// 	if (y - 1 > 0 && x - 1 > 0 && x < ft_strlen(data->map[y - 1]) && data->map[y - 1][x - 1])
// 		if (data->map[y - 1][x - 1] != '1' && data->map[y - 1][x - 1] != ' ' && data->map[y - 1][x - 1] != '\r')
// 			ft_error(data, "Map not closed diagonally");
// }

// void	handle_wall_closure(t_cub3d *data, int x, int y)
// {
// 	if (data->map[y][x + 1])
// 		if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ' && data->map[y][x + 1] != '\r')
// 			ft_error(data, "Map not closed");
// 	if (data->map[y + 1] && data->map[y + 1][x] && x < ft_strlen(data->map[y + 1]))
// 		if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ' && data->map[y + 1][x] != '\r')
			
// 	if (x - 1 > 0)
// 		if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ' && data->map[y][x - 1] != '\r')
// 			ft_error(data, "Map not closed");
// 	if (y - 1 > 0 && data->map[y - 1][x] && x < ft_strlen(data->map[y - 1]))
// 		if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ' && data->map[y - 1][x] != '\r')
// 			ft_error(data, "Map not closed");
// 	handle_wall_diagonal(data, y, x);
// }

// void	handle_pspawn(t_cub3d *data, int y, int x)
// {
// 	if (data->player.spawn_dir != 0
// 		&& (data->map[y][x] == 'N' || data->map[y][x] == 'S'
// 		|| data->map[y][x] == 'E' || data->map[y][x] == 'W'))
// 		ft_error(data, "Multiple player found");
// 	else if (data->player.spawn_dir == 0
// 		&& (data->map[y][x] == 'N' || data->map[y][x] == 'S'
// 		|| data->map[y][x] == 'E' || data->map[y][x] == 'W'))
// 	{
// 		data->player.spawn_dir = data->map[y][x];
// 		data->player.pos_x = x;
// 		data->player.pos_y = y;
// 		// data->map[y][x] = '0'; // to allow player to stand/spawn on the floor
// 	}
// 	else if (data->map[y][x] != '0' && data->map[y][x] != '1' && data->map[y][x] != '2'
// 		&& data->map[y][x] != 'N' && data->map[y][x] != 'S' && data->map[y][x] != '\r'
// 		&& data->map[y][x] != 'E' && data->map[y][x] != 'W' && data->map[y][x] != ' ')
// 	{
// 		printf("%c\n", data->map[y][x]);
// 		ft_error(data, "Invalid character in map");
// 	}
// }

// void	handle_walls(t_cub3d *data, int y, int x)
// {
// 	x = -1;
// 	while (data->map[0][++x])
// 	{
// 		if (data->map[0][x] != '1' && data->map[0][x] != ' ' && data->map[0][x] != '\r')
// 			ft_error(data, "top of the map is not closed");
// 	}
// 	x = -1;
// 	while (data->map[data->map_y - 1][++x])
// 	{
// 		if (data->map[data->map_y - 1][x] != '1'
// 			&& data->map[data->map_y - 1][x] != ' '
// 			&& data->map[data->map_y - 1][x] != '\r')
// 			ft_error(data, "bottom of the map is not closed");
// 	}
// 	y = -1;
// 	while (data->map[++y] && data->map[y][0])
// 	{
// 		if (data->map[y][0] != '1' && data->map[y][0] != ' ' && data->map[y][0] != '\r')
// 			ft_error(data, "left side of the map is not closed");
// 	}
// }

// void	handle_map(t_cub3d *data)
// {
// 	int y;
// 	int x;

// 	y = -1;
// 	while (data->map[++y])
// 	{
// 		x = -1;
// 		if (ft_strncmp(data->map[y], "\r", 1) == 0)
// 			ft_error(data, "empty line found in map.");
// 		while (data->map[y][++x])
// 		{
// 			if (data->map[y][x] == ' ' || data->map[y][x] == '\r')
// 				handle_wall_closure(data, y, x);
// 			handle_pspawn(data, y, x);
// 		}
// 		handle_walls(data, y, x);
// 	}
// }

// static void	show_map_info(t_cub3d *data)
// {
// 	printf ("MAP\n");
// 	for (int i = 0; data->map[i]; i++)
// 		printf ("%s\n", data->map[i]);
// }

int	init_file_data(t_cub3d *data, char **array)
{
	int i;
	int	result;

	i = 0;
	while (array[i])
	{
		if (i >= 0 && i <= 4)
		{
			result = init_textures(data, array[i]);
			if (result == 1)
			{
				ft_putstr_fd("Error: Invalid texture\n", 2);
				break;
			}
		}
		else if (i >= 5 && i <= 6)
		{
			result = init_fc_color(data, array[i]);
			if (result == 1)
			{
				ft_putstr_fd("Error: Invalid colour\n", 2);
				break;
			}
		}
		
		// if (ft_strncmp(array[i], " ", 1) == 0 || ft_strncmp(array[i], "1", 1) == 0)
		// {
		// 	init_map_layout(data, array, i);
		// 	handle_map(data);
		// 	break;
		// }
		// else
		// 	ft_putstr_fd("Error: Invalid file format\n", 2);
		i++;
	}
	// show_map_info(data);
	if (result == 1)
		return (1);
	return (0);
}

int	map_check(t_cub3d *data, char **array)
{
	(void)data;
	(void)array;
    if(init_file_data(data, array) == 1)
		return (1);
	return (0);
}
