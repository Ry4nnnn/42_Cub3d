#include "cub3d.h"

static void	assign_texture_path(t_cub3d *data, char *row)
{
	if (!ft_strncmp(row, "NO", 2))
		data->texture->north->path = ft_substr(row, 3, ft_strlen(row) - 4);
	else if (!ft_strncmp(row, "SO", 2))
		data->texture->south->path = ft_substr(row, 3, ft_strlen(row) - 4);
	else if (!ft_strncmp(row, "EA", 2))
		data->texture->east->path = ft_substr(row, 3, ft_strlen(row) - 4);
	else if (!ft_strncmp(row, "WE", 2))
		data->texture->west->path = ft_substr(row, 3, ft_strlen(row) - 4);
	else if (!ft_strncmp(row, "DO", 1))
		data->texture->door->path = ft_substr(row, 3, ft_strlen(row) - 3);
	else if (!ft_strncmp(row, "F", 1))
		data->texture->floor = ft_substr(row, 2, ft_strlen(row) - 3);
	else if (!ft_strncmp(row, "C", 1))
		data->texture->ceiling = ft_substr(row, 2, ft_strlen(row) - 3);
}

void	init_map_size(t_cub3d *data, char *filename)
{
	char *row;
	int	row_num;
	int fd;

	row_num = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(data, "Error\nFile failed to open\n");
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		if (row_num < 8)
			assign_texture_path(data, row);
		free(row);
		row_num++;
	}
	data->map->layout = ft_calloc((row_num - 8) + 1, sizeof(char *));
	close(fd);
}

void	init_map_layout(t_cub3d *data, char *filename)
{
	char	*row;
	int		row_num;
	int fd;

	row_num = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(data, "failed to open file\n");
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		else if (row_num < 8)
		{
			row_num++;
			free(row);
			continue ;
		}
		if (ft_strchr(row, '\t'))
		{
			free (row);
			ft_error(data, "found tab in row\n");
		}
		if (ft_strlen(row) > 1)
		{
			data->map->layout[data->map->height] = ft_strtrim(row, "\n");
			data->map->height++;
		}
		free(row);
	}
	data->map->layout[data->map->height] = NULL;
	close(fd);
}


int	check_identifier(t_cub3d *data)
{
	if (!data->texture->north->path[0] || !data->texture->south->path[0]
		|| !data->texture->west->path[0] || !data->texture->east->path[0]
		|| !data->texture->floor[0] || !data->texture->floor[0])
		return (1);
	return (0);
}

void	valid_character(t_cub3d *data, char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ')
		ft_error(data, "Invalid character in map\n");
}



void	handle_map(t_cub3d *data)
{
	int row; //y-axis
	int col; //x-axis

	row = 0;
	if (check_identifier(data) == 1)
		ft_error(data, "Missing texture.\n");
	while (data->map->layout[row])
	{
		col = 0;
		printf ("%s\n", data->map->layout[row]);
		handle_wall(data, data->map->layout[row], row);
		while (data->map->layout[row][col])
		{
			valid_character(data, data->map->layout[row][col]);
			if (data->map->layout[row][col] == 'N' || data->map->layout[row][col] == 'S'
				|| data->map->layout[row][col] == 'E' || data->map->layout[row][col] == 'W')
			{
				data->player->spawn_dir = data->map->layout[row][col];
			}
			col++;
		}
		row++;
	}
}
