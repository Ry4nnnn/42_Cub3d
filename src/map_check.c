#include "cub3d.h"

void	map_resize(t_cub3d *data);
int		check_valid_map(t_cub3d *data);
int		check_map(t_cub3d *data);

/**
 * @brief Resize the map to ensure all rows have the same width.
 *
 * This function resizes the map to ensure that all rows have the same width.
 *
 * @param data The main data structure for the application.
 */
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

/**
 * @brief Check if the map is valid.
 *
 * This function checks if the map is valid, ensuring that it contains
 * valid characters, is closed, and has only one player.
 *
 * @param data The main data structure for the application.
 * @return 1 if an error occurs, 0 otherwise.
 */
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

/**
 * @brief Check the map for invalid configurations.
 *
 * This function checks the map for invalid configurations, such as players
 * next to walls and ensures the map is properly closed.
 *
 * @param data The main data structure for the application.
 * @return 1 if an error occurs, 0 otherwise.
 */
int	check_map(t_cub3d *data)
{
	int		i;
	int		j;
	int		dir;
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
			if (data->texture->map[i][j] == 'N' || data->texture->map[i][j] == 'S'
			|| data->texture->map[i][j] == 'E' || data->texture->map[i][j] == 'W')
			{
				if (data->texture->map[i][j] == 'N')
					dir = NORTH;
				else if (data->texture->map[i][j] == 'S')
					dir = SOUTH;
				else if (data->texture->map[i][j] == 'E')
					dir = EAST;
				else if (data->texture->map[i][j] == 'W')
					dir = WEST;
				init_player_data(data, j, i, dir);
			}
		}
	}
	return (0);
}
