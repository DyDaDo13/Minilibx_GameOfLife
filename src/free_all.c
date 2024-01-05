#include "../inc/life_game.h"

void	free_map(t_data *data)
{
	int		i;

	i = -1;
	while (data->map[++i])
		free(data->map[i]);
	free(data->map);
}

void	free_list(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while ((*map))
	{
		tmp = (*map)->next;
		free((*map));
		(*map) = tmp;
	}
}

void	free_all(t_data *data)
{
	if (data->map)
		free_map(data);
	free(data);
}
