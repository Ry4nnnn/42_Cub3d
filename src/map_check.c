#include "cub3d.h"

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
	// printf ("path: |%s|\n", path);
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
		// printf("north width: %i\n", data->texture->north->width);
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
		// printf("south width: %i\n", data->texture->south->width);
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
		// printf("west width: %i\n", data->texture->west->width);
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
		// printf("east width: %i\n", data->texture->east->width);
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
		// printf("door width: %i\n", data->texture->door->width);
	}
	free (path);
	return (0);
}

/**
 * @brief Convert RGB values to hexadecimal color.
 *
 * This function takes RGB values and converts them to a hexadecimal color.
 *
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @return The hexadecimal color value.
 */
int	rgb_to_hex(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
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

int	init_map_layout(t_cub3d *data, char **array, int i)
{
		int	j;
		int	width;

		j = i;
		while (array[j])
			j++;
		data->texture->height = j - i;
		printf ("height: %i\n", data->texture->height);
		width = ft_strlen(array[i]);
		data->texture->map = ft_calloc(j - i + 1, sizeof(char *));
		j = -1;
		while (array[i])
			data->texture->map[++j] = ft_strdup(array[i++]);
		data->texture->map[++j] = NULL;
		j = -1;
		while (data->texture->map[++j])
			printf ("map: |%s|\n", data->texture->map[j]);
		j = -1;
		while (data->texture->map[++j])
		{
			if (width < ft_strlen(data->texture->map[j]))
				width = ft_strlen(data->texture->map[j]);
		}
		printf ("width: %i\n", width);
		data->texture->width = width;
		return (0);
}

int handle_wall_diagonal(t_cub3d *data, int y, int x)
{
	char **map = data->texture->map;

	if (map[y + 1] && map[y][x + 1] && map[y + 1][x + 1] && x < ft_strlen(map[y + 1]))
	{

		if (map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != ' ' && map[y + 1][x + 1] != '\r')
		{
			ft_putstr_fd("Error: Map not closed diagonally\n", 2);
			return (1);
		}
	}
	if (map[y + 1] && map[y + 1][x - 1] && x - 1 > 0 && x < ft_strlen(map[y + 1]))
	{

		if (map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != ' ' && map[y + 1][x - 1] != '\r')
		{
			ft_putstr_fd("Error: Map not closed diagonally\n", 2);
			return (1);
		}
	}
	if (y - 1 > 0 && map[y - 1][x + 1] && x < ft_strlen(map[y - 1])) if (map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != ' ' && map[y - 1][x + 1] != '\r')
	{
		ft_putstr_fd("Error: Map not closed diagonally\n", 2);
		return (1);
	}
	if (y - 1 > 0 && x - 1 > 0 && x < ft_strlen(map[y - 1]) && map[y - 1][x - 1])
	{

		if (map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != ' ' && map[y - 1][x - 1] != '\r')
		{
			ft_putstr_fd("Error: Map not closed diagonally\n", 2);
			return (1);
		}	
	}
	printf ("return 0\n");
	return (0);
}

void	map_resize(t_cub3d *data)
{
	int		w;
	int		i;
	int		j;
	char	*tmp;

	w = data->texture->width;
	i = -1;
	while (++i < data->texture->height)
	{
		if (ft_strlen(data->texture->map[i]) < w)
		{
			tmp = data->texture->map[i];
			data->texture->map[i] = ft_calloc(w + 1, sizeof(char));
			ft_strlcpy(data->texture->map[i], tmp, ft_strlen(tmp) + 1);
			j = ft_strlen(tmp);
			while (j < w)
			{
				data->texture->map[i][j] = ' ';
				j++;
			}
			data->texture->map[i][j] = '\0';
			free (tmp);
		}
	}
}

// check if map is valid
// if map contain only not 0, 1, ' ', 'N, S, E, W'
// if map is closed
// if map contain only one player

int check_valid_map(t_cub3d *data)
{
	int i;
	int j;
	int	flag;

	flag = 0;
	if (ft_strchr(data->texture->map[0], '0') || ft_strchr(data->texture->map[data->texture->height - 1], '0'))
	{
		ft_putstr_fd("Error: Map not closed\n", 2);
		return (1);
	}
	i = -1;
	while (++i < data->texture->height)
	{
		j = -1;
		while (++j < data->texture->width)
		{
			if (data->texture->map[i][j] != '0' && data->texture->map[i][j] != '1' && data->texture->map[i][j] != ' '
				&& data->texture->map[i][j] != 'N' && data->texture->map[i][j] != 'S' && data->texture->map[i][j] != '\r'
				&& data->texture->map[i][j] != 'E' && data->texture->map[i][j] != 'W')
			{
				ft_putstr_fd("Error: Invalid character in map\n", 2);
				return (1);
			}
			if (data->texture->map[i][j] == 'N' || data->texture->map[i][j] == 'S' || data->texture->map[i][j] == 'E' || data->texture->map[i][j] == 'W')
				flag++;
		}
	}
	if (flag != 1)
	{
		ft_putstr_fd("Error: Invalid number of players\n", 2);
		return (1);
	}
	return (0);
}

int	check_map(t_cub3d *data)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	map = data->texture->map;
	while (++i < data->texture->height)
	{
		j = -1;
		while (++j < data->texture->width)
		{
			if (data->texture->map[i][j] == '0'|| data->texture->map[i][j] == 'N' \
			|| data->texture->map[i][j] == 'S' || data->texture->map[i][j] == 'E' \
			|| data->texture->map[i][j] == 'W')
			{
				if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ' || map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
				{
					ft_putstr_fd("Error: Invalid Map\n", 2);
					return (1);
				}
			}
		}
	}
	return (0);
}

int	handle_map(t_cub3d *data)
{

	if (check_valid_map(data) == 1)
		return (1);
	if (check_map(data) == 1)
		return (1);
	return (0);
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
	if (array == NULL)
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		return (1);
	}
	while (array[i])
	{
		if (i >= 0 && i <= 4)
		{
			// printf("array[%i]: |%s|\n", i, array[i]);
			result = init_textures(data, array[i]);
			if (result == 1)
			{
				ft_putstr_fd("Error: Invalid texture\n", 2);
				break;
			}
		}
		else if (i >= 5 && i <= 6)
		{
			// printf("array[%i]: |%s| FC\n",i,  array[i]);
			result = init_fc_color(data, array[i]);
			if (result == 1)
			{
				ft_putstr_fd("Error: Invalid colour\n", 2);
				break;
			}
		}
		else if (ft_strncmp(array[i], " ", 1) == 0 || ft_strncmp(array[i], "1", 1) == 0)
		{
				// printf("i: %i\n", i);
				// printf("array[%i]: |%s|\n", i, array[i]);
				result = init_map_layout(data, array, i);
				if (result == 1)
					break;
				map_resize(data);
				result = handle_map(data);
				if (result == 1)
					break;
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
 * @brief Check and initialize map data.
 *
 * This function checks and initializes map-related data by calling the
 * `init_file_data` function. It processes an array of strings representing
 * lines from a configuration file.
 *
 * @param data The main data structure for the application.
 * @param array An array of strings representing lines from the file.
 * @return 1 if an error occurs during initialization, 0 otherwise.
 */
int	map_check(t_cub3d *data, char **array)
{
    if(init_file_data(data, array) == 1)
		return (1);
	return (0);
}
