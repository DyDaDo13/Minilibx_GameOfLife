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
	draw_map(data->map, data);
	data->gen = 0;
	data->gen++;
	mlx_string_put(data->mlx, data->win, 6, 12, -200, ft_itoa(data->gen));
	mlx_string_put(data->mlx, data->win, 6, 28, 2000, ft_itoa(data->rule)); 
	return (0);
}