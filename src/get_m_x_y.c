#include "../inc/life_game.h"

void	get_m_x_y(t_data *data, int x, int y)
{
	int		i = 0;
	while (data->m_x < x)
	{
		data->m_x += 16;
		i++;
	}
	data->m_x = i - 1;
	i = 0;
	while (data->m_y < y)
	{
		data->m_y += 16;
		i++;
	}
	data->m_y = i - 1;
	i = 0;
	data->i_x = (data->m_x * 16);
	data->i_y = (data->m_y * 16);
}