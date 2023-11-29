#include "cub3d.h"

int		check_valid_filename(char *filename);
char	**open_file(char *filename);
int		parsing(t_cub3d *data, char *filename);

int	check_valid_filename(char *filename)
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

char	**open_file(char *filename)
{
	int fd;
	int	i;
	char buf[1024];
	char **array;

	if (check_valid_filename(filename) == 1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File not found!\n", 2);
		return (NULL);
	}
	i = read(fd, buf, 1024);
	buf[i] = '\0';
	array = ft_split(buf, '\n');
	return (array);
}

int	parsing(t_cub3d *data, char *filename)
{
	char	**array;

	if (check_valid_filename(filename) == 1)
		return(1);
	array = NULL;
	array  = open_file(filename);
	if (array == NULL)
		return (1);
	// if (map_check(data, array) == 1)
	// {
	// 	free_2d(array);
	// 	return (1);
	// }
	handle_file(data, array);
	free_2d(array);
	return (0);
}