#include "cub3d.h"

// static void	prinitf_map_info(t_cub3d *data)
// {
// 	t_list	*tmp;

// 	tmp = data->map_info;
// 	while (tmp != NULL)
// 	{
// 		printf("[%c] ", ((t_map_info *)tmp->content)->key);
// 		printf("[%s]\n", ((t_map_info *)tmp->content)->value);
// 		tmp = tmp->next;
// 	}
// }

// int	init_map(t_cub3d *data, char **file)
// {
// 	char **map;

// 	// map = ft_calloc(j - 6 + 1, sizeof(char *));
// 	// if (!map)
// 	// 	return (1);
// 	// j = 0;
// 	// while (file[i])
// 	// {
// 	// 	map[j] = ft_strdup(file[i]);
// 	// 	if (!map[j])
// 	// 		return (1);
// 	// 	j++;
// 	// 	i++;
// 	// }
// 	// j = -1;
// 	// while (map[++j] != NULL)
// 	// 	printf("|%s|\n", map[j]);
// 	data->map = map;
// 	return (0);
// }

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
		data->map = malloc(sizeof(char **) * (j - i + 1));
		j = -1;
		while (array[i])
			data->map[++j] = ft_strdup(array[i++]);
		data->map[++j] = NULL;
		// ft_strlcat(data->map[0], "\r\0", ft_strlen(data->map[0]) + 2);
}

void	handle_wall_closure(t_cub3d *data, int x, int y)
{
	if (data->map[y][x + 1])
		if (data->map[y][])
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
			handle_spawn(data);

		}
	}
}

static void	show_map_info(t_cub3d *data)
{
	printf ("MAP\n");
	for (int i = 0; data->map[i]; i++)
		printf ("%s\n", data->map[i]);
}

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
		i++;
	}
	show_map_info(data);
	return (0);
}


// void	check_valid_map(t_cub3d	*data)
// {
// 	(void)data;
// }

int	map_check(t_cub3d *data, char **array)
{
    if(init_file_data(data, array) == 1)
		return (1);
	// check_valid_map(data); 
	return (0);
}
