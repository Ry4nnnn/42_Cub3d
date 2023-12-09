#include "cub3d.h"

int		parsing(t_cub3d *data, char *filename);
char	**open_file(char *filename);

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

	array = NULL;
	array  = open_file(filename);
	if (array == NULL)
	{
		ft_putstr_fd("Error: Can't open file\n", 2);
		return (1);
	}
	init_data(data);
	if(init_file_data(data, array) == 1)
	{
		free_2d(array);
		return (1);
	}
	free_2d(array);
	map_resize(data);
	if (check_valid_map(data) == 1)
		return (1);
	if (check_map(data) == 1)
		return (1);
	return (0);
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
	char	buf[2000];
	char	**array;

	if (check_valid_filename(filename) == 1)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("File not found!\n", 2);
		return (NULL);
	}
	i = read(fd, buf, 2000);
	buf[i] = '\0';
	array = ft_split(buf, '\n');
	return (array);
}
