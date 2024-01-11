#include "../inc/life_game.h"

int	is_dead(t_data *data)
{
	int		count = 0;
	int		x = data->bloc_posx;
	int		y = data->bloc_posy;

	if (x - 1 >= 0)
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
	if ((y - 1) >= 0 && (x - 1) >= 0)
		if (data->map[y - 1][x - 1] && data->map[y - 1][x - 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x + 1] && data->map[y + 1][x + 1] == '1')
			count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x + 1] && data->map[y - 1][x + 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1) && (x - 1) >= 0)
		if (data->map[y + 1][x - 1] && data->map[y + 1][x - 1] == '1')
			count++;
	if (count > data->rule || count < 2) // rules
		return (1);
	return (0);
}

int	is_born(t_data *data)
{
	int		count = 0;
	int		x = data->bloc_posx;
	int		y = data->bloc_posy;

	if (x - 1 >= 0)
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
	if ((y - 1) >= 0 && (x - 1) >= 0)
		if (data->map[y - 1][x - 1] && data->map[y - 1][x - 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1))
		if (data->map[y + 1][x + 1] && data->map[y + 1][x + 1] == '1')
			count++;
	if (y - 1 >= 0)
		if (data->map[y - 1][x + 1] && data->map[y - 1][x + 1] == '1')
			count++;
	if (y + 1 <= (data->map_height - 1) && (x - 1) >= 0)
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
				data->bloc_posy = data->i;
				data->bloc_posx = data->j;
				data->i_pix = data->i * 16;
				data->j_pix = data->j * 16;
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
				data->bloc_posy = data->i;
				data->bloc_posx = data->j;
				data->i_pix = data->i * 16;
				data->j_pix = data->j * 16;
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

void	free_map2(char **map)
{
	int		i = -1;

	while (map[++i])
		free(map[i]);
	free(map);
}

int	algorithm(t_data *data)
{
	char		*temp;
	char		**cpy;
	data->i = 0;
	data->j = 0;
	data->i_pix = 0;
	data->j_pix = 0;

	cpy = map_cpy(data->map);
	while (find_block(data) == 1)
	{
		if (is_dead(data) == 1)
		{
			cpy[data->bloc_posy][data->bloc_posx] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.empty.image, data->j_pix, data->i_pix);
		}
	}
	data->i = 0;
	data->j = 0;
	data->i_pix = 0;
	data->j_pix = 0;
	while (find_block2(data) == 1)
	{
		if (is_born(data) == 1)
		{
			cpy[data->bloc_posy][data->bloc_posx] = '1';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.full.image, data->j_pix, data->i_pix);
		}
	}
	free_map(data);
	data->map = map_cpy(cpy);
	free_map2(cpy);
	refresh_counter(data);
	//draw_map(data->map, data);
	data->gen++;
	temp = ft_itoa(data->gen);
	mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
	free(temp);
	temp = ft_itoa(data->rule);
	mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
	free(temp);
	return (0);
}
