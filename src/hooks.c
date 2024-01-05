#include "../inc/life_game.h"

int		mouse_hook(int mc, int x, int y, t_data *data)
{
	data->m_x = 0;
	data->m_y = 0;
	if (mc == 1)
	{
		get_m_x_y(data, x, y);
		if (data->map[data->m_y][data->m_x] == '0')
		{
			data->map[data->m_y][data->m_x] = '1';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.full.image, data->i_x, data->i_y);
		}
		else if (data->map[data->m_y][data->m_x] == '1')
		{
			data->map[data->m_y][data->m_x] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.empty.image, data->i_x, data->i_y);
		}
		//printf("map = %c\n", data->map[data->m_y][data->m_x]);
		//printf("x = %i y = %i\n\033[31mm_x = %i m_y = %i\033[34m\ni_x = %i i_y = %i\033[0m\n", x, y, data->m_x, data->m_y, data->i_x, data->i_y);
	}
	return (0);
}

int	ft_key_check(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_stop(data);
	if (key == XK_space)
		algorithm(data);
	if (key == XK_r)
		reset(data);
	return (0);
}