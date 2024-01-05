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
	data->map_cpy = reset_map(data->map_cpy, '0');
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (0);
}