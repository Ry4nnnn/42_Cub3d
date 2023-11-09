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
		// if (i != 3)
		// {
		// 	printf ("invalid ceiling color\n");
		// 	return (1);
		// }
		data->texture.floor[0] = ft_atoi(&str[2]);
		data->texture.floor[1] = ft_atoi(ft_strchr(&str[2], ',') + 1);
		data->texture.floor[2] = ft_atoi(ft_strchr(ft_strchr(&str[2], ',') + 1, ',') + 1);
		while (data->texture.floor[i])
		{
			if (data->texture.floor[i] < 0 || data->texture.floor[i] > 255)
			
			i++;
		}
		printf ("%i\n", data->texture.floor[2]);
	}
	return (0);
}

int	init_map_data(t_cub3d *data, char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		// init_textures(data, array[i]);
		init_fc_color(data, array[i]);
		// if (init_map(data, array[i]) == 1)
		// 	return (1);
		i++;
	}
	return (0);
}


void	check_valid_map(t_cub3d	*data)
{
	(void)data;
}

int	map_check(t_cub3d *data, char **array)
{
    if(init_map_data(data, array) == 1)
		return (1);
	check_valid_map(data);
	return (0);
}
