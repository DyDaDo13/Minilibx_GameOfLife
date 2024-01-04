#include "../inc/life_game.h"

int	is_dead(t_data *data)
{
	int		count = 0;
	int		x = data->b_x;
	int		y = data->b_y;

	if (data->map_cpy[y][x - 1] && data->map_cpy[y][x - 1] == '1')
		count++;
	if (data->map_cpy[y][x + 1] && data->map_cpy[y][x + 1] == '1')
		count++;
	if (data->map_cpy[y - 1][x] && data->map_cpy[y - 1][x] == '1')
		count++;
	if (data->map_cpy[y + 1][x] && data->map_cpy[y + 1][x] == '1')
		count++;
	if (data->map_cpy[y - 1][x - 1] && data->map_cpy[y - 1][x - 1] == '1')
		count++;
	if (data->map_cpy[y + 1][x + 1] && data->map_cpy[y + 1][x + 1] == '1')
		count++;
	if (data->map_cpy[y - 1][x + 1] && data->map_cpy[y - 1][x + 1] == '1')
		count++;
	if (data->map_cpy[y + 1][x - 1] && data->map_cpy[y + 1][x - 1] == '1')
		count++;
	if (count > 3 || count < 2)
		return (1);
	return (0);
}
int	find_block(t_data *data)
{
	printf("i = %ij = %i\n", data->i, data->j);
	while (data->map_cpy[data->i])
	{
		while (data->map_cpy[data->i][data->j])
		{
			if (data->map_cpy[data->i][data->j] && data->map_cpy[data->i][data->j] == '1')
			{
				data->b_y = data->i;
				data->b_x = data->j;
				if (data->map_cpy[data->i][data->j + 1] != '\0')
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

int	algorithm(t_data *data)
{
	//char	**cpy_cpy;
	//int		i = 0;
	//int		x = 0;
	//int		y = 0;
	data->i = 0;
	data->j = 0;
	// data->b_x = 0;
	// data->b_y = 0;

	//printf("test\n");
	//cpy_cpy = data->map_cpy;
	while (find_block(data) == 1)
	{
		printf("b_y = %i\nb_x = %i\n", data->b_y, data->b_x);
		if (is_dead(data) == 1)
			printf("mort\n");
		else
			printf("vie\n");
		usleep(200);
	}
	return (0);
} 