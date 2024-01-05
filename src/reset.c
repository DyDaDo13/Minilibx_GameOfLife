#include "../inc/life_game.h"

char	**reset_map(char **str, char c)
{
	int		i = -1;
	int		j;

	while (str[++i])
	{
		j = 0;
		while(str[i][j])
		{
			str[i][j] = c;
			j++;
		}
	}
	return (str);
}

int	reset(t_data *data)
{
	data->map = reset_map(data->map, '0');
	mlx_clear_window(data->mlx, data->win);
	draw_map(data->map, data);
	data->gen = 0;
	return (0);
}