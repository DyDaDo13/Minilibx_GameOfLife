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
	if (key == 49)
		damed_map(data);
	if (key == 50)
		random_map(data);
	if (key == 51)
	{
		draw_map(data->map, data);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, ft_itoa(data->rule = 3));
		mlx_string_put(data->mlx, data->win, 6, 12, -200, ft_itoa(data->gen));
	}
	if (key == 52)
	{
		draw_map(data->map, data);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, ft_itoa(data->rule = 4));
		mlx_string_put(data->mlx, data->win, 6, 12, -200, ft_itoa(data->gen));
	}
	if (key == 53)
	{
		draw_map(data->map, data);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, ft_itoa(data->rule = 5));
		mlx_string_put(data->mlx, data->win, 6, 12, -200, ft_itoa(data->gen));
	}
	if (key == 54)
	{
		draw_map(data->map, data);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, ft_itoa(data->rule = 6));
		mlx_string_put(data->mlx, data->win, 6, 12, -200, ft_itoa(data->gen));
	}
	return (0);
}