#include "cub3d.h"



int	check_valid_filename(t_cub3d *data, char *filename)
{
	int		file_len;
	char	*res;
	int		valid;

	file_len = ft_strlen(filename);
	if (file_len >= 5)
	{
		res = ft_strnstr(filename, ".cub", file_len);
		if (res != NULL)
		{
			valid = ft_strncmp(res, ".cub", 4);
			if (valid == 0 && ft_strlen(res) == 4)
				return (0);
		}
	}
	ft_putendl_fd("invalid filename", 2);
	return (1);
}

int main(int argc, char	**argv)
{
	t_cub3d	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./program_name [map_path]\n", 2);
		return (1);
	}
	if (check_valid_filename(&data, argv[1]) == 1)
		return(1);
	init_data(&data, argv[1]);
	handle_map(&data);
	init_window(&data);
	// mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	// mlx_hook(data->win, 2, 1L << 0, NULL, &data);
	// mlx_loop(data->mlx);
	return (0);
}