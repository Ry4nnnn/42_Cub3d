#include "cub3d.h"

int error_check(t_cub3d *data, int argc, char **argv);   
int check_valid_filename(char *filename);

/**
 * @brief Checks command-line arguments, initializes program data, and performs parsing.
 *
 * This function checks if the correct number of command-line arguments is provided,
 * initializes the main data structure, and performs parsing of the configuration file.
 * It also handles errors and provides usage instructions if needed.
 *
 * @param data A pointer to the main data structure of the program.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 on successful initialization and parsing, 1 on error.
 */
int	error_check(t_cub3d *data, int argc, char **argv)
{
	init_data(data);
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./program [map]\n", 2);
		return (1);
	}
    if (check_valid_filename(argv[1]) == 1)
		return(1);
	if (parsing(data, argv[1]) == 1)
		return (1);
	return (0);
}

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