#include "../inc/life_game.h"

void	get_m_x_y(t_data *data, int x, int y)
{
	int		i = 0;
	while (data->mouse_posx < x)
	{
		data->mouse_posx += 16;
		i++;
	}
	data->mouse_posx = i - 1;
	i = 0;
	while (data->mouse_posy < y)
	{
		data->mouse_posy += 16;
		i++;
	}
	data->mouse_posy = i - 1;
	i = 0;
	data->image__posx = (data->mouse_posx * 16);
	data->image__posy = (data->mouse_posy * 16);
}