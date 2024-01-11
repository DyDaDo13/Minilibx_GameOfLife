#include "../inc/life_game.h"

int		mouse_hook(int mc, int x, int y, t_data *data)
{
	char	*temp;
	data->mouse_posx = 0;
	data->mouse_posy = 0;
	if (mc == 1)
	{
		get_m_x_y(data, x, y);
		if (data->map[data->mouse_posy][data->mouse_posx] == '0')
		{
			data->map[data->mouse_posy][data->mouse_posx] = '1';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.full.image, data->image__posx, data->image__posy);
			temp = ft_itoa(data->gen);
			mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
			free(temp);
			temp = ft_itoa(data->rule);
			mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
			free(temp);
		}
		else if (data->map[data->mouse_posy][data->mouse_posx] == '1')
		{
			data->map[data->mouse_posy][data->mouse_posx] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.empty.image, data->image__posx, data->image__posy);
			temp = ft_itoa(data->gen);
			mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
			free(temp);
			temp = ft_itoa(data->rule);
			mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
			free(temp);
		}
	}
	return (0);
}

int	ft_key_check(int key, t_data *data)
{
	char	*temp;
	if (key == XK_Escape)
		ft_stop(data);
	if (key == XK_space)
	{
		algorithm(data);
		data->state = 0;
	}
	if (key == XK_r)
		reset(data);
	if (key == XK_a)
		data->state = !data->state;
	if (key == 49)
		damed_map(data);
	if (key == 50)
		random_map(data);
	if (key == 51)
	{
		draw_map(data->map, data);
		temp = ft_itoa(data->rule = 3);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
		free(temp);
		temp = ft_itoa(data->gen);
		mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
		free(temp);
	}
	if (key == 52)
	{
		draw_map(data->map, data);
		draw_map(data->map, data);
		temp = ft_itoa(data->rule = 4);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
		free(temp);
		temp = ft_itoa(data->gen);
		mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
		free(temp);
	}
	if (key == 53)
	{
		draw_map(data->map, data);
		draw_map(data->map, data);
		temp = ft_itoa(data->rule = 5);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
		free(temp);
		temp = ft_itoa(data->gen);
		mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
		free(temp);
	}
	if (key == 54)
	{
		draw_map(data->map, data);
		draw_map(data->map, data);
		temp = ft_itoa(data->rule = 6);
		mlx_string_put(data->mlx, data->win, 6, 28, 2000, temp);
		free(temp);
		temp = ft_itoa(data->gen);
		mlx_string_put(data->mlx, data->win, 6, 12, -200, temp);
		free(temp);
	}
	return (0);
}