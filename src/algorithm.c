#include "../inc/life_game.h"

int	is_dead(t_data *data)
{
	int		count = 0;
	int		x = data->b_x;
	int		y = data->b_y;

	if (data->map[y][x - 1] && data->map[y][x - 1] == '1')
		count++;
	if (data->map[y][x + 1] && data->map[y][x + 1] == '1')
		count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x] && data->map[y - 1][x] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x] && data->map[y + 1][x] == '1')
			count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x - 1] && data->map[y - 1][x - 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x + 1] && data->map[y + 1][x + 1] == '1')
			count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x + 1] && data->map[y - 1][x + 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x - 1] && data->map[y + 1][x - 1] == '1')
			count++;
	if (count > 3 || count < 2) // rules
		return (1);
	return (0);
}

int	is_born(t_data *data)
{
	int		count = 0;
	int		x = data->b_x;
	int		y = data->b_y;

	if (data->map[y][x - 1] && data->map[y][x - 1] == '1')
		count++;
	if (data->map[y][x + 1] && data->map[y][x + 1] == '1')
		count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x] && data->map[y - 1][x] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x] && data->map[y + 1][x] == '1')
			count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x - 1] && data->map[y - 1][x - 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x + 1] && data->map[y + 1][x + 1] == '1')
			count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x + 1] && data->map[y - 1][x + 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x - 1] && data->map[y + 1][x - 1] == '1')
			count++;
	if (count == 3) //rules
		return (1);
	return (0);
}

int	find_block(t_data *data)
{
	while (data->map[data->i])
	{
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] && data->map[data->i][data->j] == '1')
			{
				data->b_y = data->i;
				data->b_x = data->j;
				if (data->map[data->i][data->j + 1] != '\0')
					data->j++;
				else
				{
					data->j = 0;
					data->i++;
				}
				return (1);
			}
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	return (0);
}

int	is_block(t_data *data)
{
	int		x = data->j;
	int		y = data->i;

	if (data->map[y][x] != '1')
	{
		if (x - 1 >= 0)
			if (data->map[y][x - 1] && data->map[y][x - 1] == '1')
				return (1);
		if (x + 1 <= data->map_width - 1)
			if (data->map[y][x + 1] && data->map[y][x + 1] == '1')
				return (1);
		if (y - 1 >= 0)
			if (data->map[y - 1][x] && data->map[y - 1][x] == '1')
				return (1);
		if (y + 1 <= (data->map_height - 1))
			if (data->map[y + 1][x] && data->map[y + 1][x] == '1')
				return (1);
		if ((y - 1 >= 0) && (x - 1 >= 0))
			if (data->map[y - 1][x - 1] && data->map[y - 1][x - 1] == '1')
				return (1);
		if (y + 1 <= (data->map_height - 1) && (x + 1 <= data->map_width - 1))
			if (data->map[y + 1][x + 1] && data->map[y + 1][x + 1] == '1')
				return (1);
		if (y - 1 >= 0 && (x + 1 <= data->map_width - 1))
			if (data->map[y - 1][x + 1] && data->map[y - 1][x + 1] == '1')
				return (1);
		if (y + 1 <= (data->map_height - 1) && (x - 1 >= 0))
			if (data->map[y + 1][x - 1] && data->map[y + 1][x - 1] == '1')
				return (1);
	}
	return (0);
}

int	find_block2(t_data *data)
{
	while (data->map[data->i])
	{
		while (data->map[data->i][data->j])
		{
			if (is_block(data) == 1)
			{
				data->b_y = data->i;
				data->b_x = data->j;
				if (data->map[data->i][data->j + 1] != '\0')
					data->j++;
				else
				{
					data->j = 0;
					data->i++;
				}
				return (1);
			}
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	return (0);
}


void	refresh_map(t_data *data, char **map)
{
	mlx_clear_window(data->mlx, data->win);
	draw_map(map, data);
}

void	free_map2(char **map)
{
	int		i = -1;

	while (map[++i])
		free(map[i]);
	free(map);
}

int	algorithm(t_data *data)
{
	char		**cpy;
	data->i = 0;
	data->j = 0;

	cpy = map_cpy(data->map);
	while (find_block(data) == 1)
	{
		if (is_dead(data) == 1)
			cpy[data->b_y][data->b_x] = '0';
	}
	data->i = 0;
	data->j = 0;
	while (find_block2(data) == 1)
	{
		if (is_born(data) == 1)
			cpy[data->b_y][data->b_x] = '1';
	}
	free_map(data);
	data->map = map_cpy(cpy);
	free_map2(cpy);
	refresh_map(data, data->map);
	printf("Generation %i\n", data->gen++);
	return (0);
}
