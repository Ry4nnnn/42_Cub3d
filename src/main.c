#include "cub3d.h"

static void check_valid_filename(char *filename)
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
				return ;
		}
	}
	ft_putendl_fd("invalid filename", 2);
	exit (1);
}

char	**open_file(t_cub3d *data, char *filename)
{
	int fd;
	int	i;
	char buf[1024];
	char **array;

	check_valid_filename(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf ("File not found!");
		exit (1);
	}
	i = read(fd, buf, 1024);
	buf[i] = '\0';
	array = ft_split(buf, '\n');
	return (array);
}

void	parsing(t_cub3d *data, char *filename)
{
	printf ("check\n");
	char **array  = open_file(data, filename);

}

int main(int argc, char	**argv)
{
	t_cub3d	data;

	if (argc != 2)
	{
		printf("Usage: ./program [map]");
		exit(1);
	}
	parsing(&data, argv[1]);
	// data.mlx = mlx_init();
	// data.win = mlx_new_window(data.mlx, 1000, 500, "cub3d");
	// mlx_hook(data.win, 2, 1L << 0, NULL, &data);
	// mlx_loop(data.mlx);
	return (0);
}