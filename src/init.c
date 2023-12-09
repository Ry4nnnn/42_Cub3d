#include "cub3d.h"

void	init_data(t_cub3d *data);
int		init_file_data(t_cub3d *data, char **array);
int		init_textures(t_cub3d *data, char *str);
int		init_fc_color(t_cub3d *data, char *str);
int		init_map_layout(t_cub3d *data, char **array, int i);
void	init_player_data(t_cub3d *data, int x, int y, int dir);
/**
 * @brief Initialize the main data structure.
 *
 * This function initializes the main data structure for the application,
 * including memory allocation for textures, the player, and the ray.
 *
 * @param data The main data structure for the application.
 */
void    init_data(t_cub3d *data)
{
	data->mlx = mlx_init();
	data->texture = ft_calloc(1, sizeof(t_texture));
	data->texture->north = ft_calloc(1, sizeof(t_img_data));
	data->texture->south = ft_calloc(1, sizeof(t_img_data));
	data->texture->west = ft_calloc(1, sizeof(t_img_data));
	data->texture->east = ft_calloc(1, sizeof(t_img_data));
	data->texture->door = ft_calloc(1, sizeof(t_img_data));
    data->player = ft_calloc(1, sizeof(t_player));
    data->player->dirx = -1;
    data->player->diry =  0;
    data->player->planex = 0;
    data->player->planey = 0.45;
    data->player->t = 0;
    data->player->old_t = 0;
    data->ray = ft_calloc(1, sizeof(t_ray));
	data->ray->north_south = -1;
	data->ray->east_west = -1;
}

/**
 * @brief Initialize data from a file.
 *
 * This function reads an array of strings, typically representing lines
 * from a configuration file, and initializes various components of the
 * t_cub3d structure, including textures and color settings.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the file.
 * @return 1 if an error occurs, 0 otherwise.
 */
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
		else if (ft_strncmp(array[i], " ", 1) == 0 || ft_strncmp(array[i], "1", 1) == 0)
		{
				result = init_map_layout(data, array, i);
				break;
		}
		else
			ft_putstr_fd("Error: Invalid file format\n", 2);
		i++;
	}
	if (result == 1)
		return (1);
	return (0);
}

/**
 * @brief Initialize textures based on a given string.
 *
 * This function initializes texture data structures based on a string
 * representing a line from the configuration file. It handles different
 * types of textures, such as north, south, west, east, and door textures.
 *
 * @param data The main data structure for the application.
 * @param str The string representing a line from the configuration file.
 * @return 1 if an error occurs, 0 otherwise.
 */
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
	}
	else
	{
		free (path);
		return (1);
	}
	free (path);
	return (0);
}



/**
 * @brief Initialize floor and ceiling colors based on a given string.
 *
 * This function initializes floor and ceiling colors based on a string
 * representing a line from the configuration file. It handles the 'F' and 'C'
 * options, parsing RGB values and converting them to hexadecimal colors.
 *
 * @param data The main data structure for the application.
 * @param str The string representing a line from the configuration file.
 * @return 1 if an error occurs, 0 otherwise.
 */
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
	}
	else
	{
		free_2d(array);
		free_2d(num);
		return (1);
	}
	free_2d(array);
	free_2d(num);
	return (0);
}

/**
 * @brief Initialize map layout based on a given array of strings.
 *
 * This function initializes map layout based on an array of strings
 * representing lines from the configuration file.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the configuration file.
 * @param i Index to start processing in the array.
 * @return 0 if successful, otherwise 1.
 */
int	init_map_layout(t_cub3d *data, char **array, int i)
{
		int	j;
		int	width;

		j = i;
		while (array[j])
			j++;
		data->texture->height = j - i;
		width = ft_strlen(array[i]);
		data->texture->map = ft_calloc(j - i + 1, sizeof(char *));
		j = -1;
		while (array[i])
			data->texture->map[++j] = ft_strdup(array[i++]);
		data->texture->map[++j] = NULL;
		j = -1;
		while (data->texture->map[++j])
		{
			if (width < ft_strlen(data->texture->map[j]))
				width = ft_strlen(data->texture->map[j]);
		}
		data->texture->width = width;
		return (0);
}

void	init_player_data(t_cub3d *data, int x, int y, int dir)
{
	data->player->px = x + 0.2;
	data->player->py = y + 0.2;
	(void)dir;
	if (dir == NORTH)
	{
		data->player->dirx = 0;
		data->player->diry = -1;
		data->player->planex = -0.45;
		data->player->planey = 0;
	}
	else if (dir == SOUTH)
	{
		data->player->dirx = 0;
		data->player->diry = 1;
		data->player->planex = 0.45;
		data->player->planey = 0;
	}
	else if (dir == EAST)
	{
		data->player->dirx = 1;
		data->player->diry = 0;
		data->player->planex = 0;
		data->player->planey = -0.45;
	}
	else if (dir == WEST)
	{
		data->player->dirx = -1;
		data->player->diry = 0;
		data->player->planex = 0;
		data->player->planey = 0.45;
	}
}