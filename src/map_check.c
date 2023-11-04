#include "cub3d.h"

void	printf_map_info(t_cub3d *data)
{
	t_list	*tmp;

	tmp = data->map_info;
	while (tmp != NULL)
	{
		printf("[%c] ", ((t_map_info *)tmp->content)->key);
		printf("[%s]\n", ((t_map_info *)tmp->content)->value);
		tmp = tmp->next;
	}
}

int	init_map(t_cub3d *data, char **file, int i, int j)
{
	char **map;

	map = ft_calloc(j - 6 + 1, sizeof(char *));
	if (!map)
		return (1);
	j = 0;
	while (file[i])
	{
		map[j] = ft_strdup(file[i]);
		if (!map[j])
			return (1);
		j++;
		i++;
	}
	data->map = map;
	return (0);
}

int	init_map_data(t_cub3d *data, char **file)
{
    int			i;
    int			j;
    char		**split;
    t_map_info	*content;
	t_list		*node;

	j = -1;
	while (file[++j] != NULL);
	if (j < 9)
	{
		ft_putstr_fd("map too little information\n", 2);
		return (1);
	}
    i = 0;
	while (i < 6)
	{
		split = ft_split(file[i], ' ');
		content = ft_calloc(1, sizeof(t_map_info));
		content->key = split[0][0];
		content->value = ft_strdup(split[1]);
		node = ft_lstnew(content);
		ft_lstadd_back(&data->map_info, node);
		free_2d(split);
		i++;
	}
	if (init_map(data, file, i, j) == 1)
		return (1);
	return (0);
}


void	check_valid_map(t_cub3d	*data)
{
	(void)data;
}

int	map_check(t_cub3d *data, char **file)
{
    if(init_map_data(data, file) == 1)
		return (1);
	check_valid_map(data);
	return (0);
}
