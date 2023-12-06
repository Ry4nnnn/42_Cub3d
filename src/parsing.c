#include "cub3d.h"

int		check_valid_filename(char *filename);
char	**open_file(char *filename);
int		parsing(t_cub3d *data, char *filename);

/**
 * @brief Check if a filename has a valid extension.
 *
 * This function checks if the given filename has a valid extension ".cub".
 *
 * @param filename The name of the file to be checked.
 * @return 0 if the filename is valid, 1 otherwise.
 */
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

/**
 * @brief Open a file and read its content into an array of strings.
 *
 * This function opens the specified file, reads its content, and splits it
 * into an array of strings using '\n' as the delimiter.
 *
 * @param filename The name of the file to be opened.
 * @return An array of strings containing the file content, or NULL on failure.
 */
char	**open_file(char *filename)
{
	int 	fd;
	int		i;
	char	buf[1024];
	char	**array;

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

/**
 * @brief Parse the content of a configuration file.
 *
 * This function parses the content of a configuration file using the map_check
 * function. It checks the filename validity, opens the file, and performs the parsing.
 *
 * @param data The main data structure for the application.
 * @param filename The name of the configuration file to be parsed.
 * @return 1 if an error occurs during parsing, 0 otherwise.
 */
int	parsing(t_cub3d *data, char *filename)
{
	char	**array;

	if (check_valid_filename(filename) == 1)
		return(1);
	array = NULL;
	array  = open_file(filename);
	if (array == NULL)
		return (1);
	if (map_check(data, array) == 1)
	{
		free_2d(array);
		return (1);
	}
	free_2d(array);
	return (0);
}