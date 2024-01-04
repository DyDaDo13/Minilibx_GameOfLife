#include "../inc/life_game.h"

int	ft_stop(t_data *data)
{
	return (destroy_all_images(data), mlx_destroy_window(data->mlx, data->win), mlx_destroy_display(data->mlx), free(data->mlx), free_all(data), exit(1), 0);
}

int	ft_key_check(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_stop(data);
	if (key == XK_space)
		algorithm(data);
	return (0);
}

void	draw_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		data->x = 0;
		while (data->map[i][j])
		{
			draw_images(data, i, j);
			j++;
			data->x += 16;
		}
		data->y += 16;
		i++;
	}
}

int		mouse_hook(int mc, int x, int y, t_data *data)
{
	data->m_x = 0;
	data->m_y = 0;
	if (mc == 1)
	{
		get_m_x_y(data, x, y);
		if (data->map_cpy[data->m_y][data->m_x] == '0')
		{
			data->map_cpy[data->m_y][data->m_x] = '1';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.full.image, data->i_x, data->i_y);
		}
		else if (data->map_cpy[data->m_y][data->m_x] == '1')
		{
			data->map_cpy[data->m_y][data->m_x] = '0';
			mlx_put_image_to_window(data->mlx, data->win, data->sprites.empty.image, data->i_x, data->i_y);
		}
		// int		i = 0;
		// while (data->map_cpy[i])
		// {
		// 	printf("%s\n", data->map[i]);
		// 	i++;
		// }
		// i = 0;
		printf("map = %c\n", data->map_cpy[data->m_y][data->m_x]);
		printf("x = %i y = %i\n\033[31mm_x = %i m_y = %i\033[34m\ni_x = %i i_y = %i\033[0m\n", x, y, data->m_x, data->m_y, data->i_x, data->i_y);
	}
	return (0);
}

void	ft_display(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->b_x = 0;
	data->b_y = 0;
	data->gen = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 16), ((data->map_height) * 16), "GAME OF LIFE");
	init_images(data);
	draw_map(data);
	mlx_hook(data->win, 3, (1L << 0) + (1L << 1), ft_key_check, data);
	mlx_hook(data->win, ButtonPress, (1L << 2), mouse_hook, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
}

int	main(void)
{
	t_data	*data;
	int		fd;
	
	data = malloc(sizeof(t_data));
	fd = open("map/map.txt", O_RDONLY);
	data->map = init_map(fd, data);
	data->map_cpy = data->map;
	ft_display(data);
	// int	i = 0;
	// while(map[i])
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	// printf("%i\n%i\n", data->map_height, data->map_width);
	// map[1] = get_next_line(fd);
	// printf("%s\n", map[1]);
	// map[2] = get_next_line(fd);
	// printf("%s\n", map[2]);
	// map[3] = get_next_line(fd);
	// printf("%s\n", map[3]);
	// map[4] = get_next_line(fd);
	// printf("%s\n", map[4]);
	// map[5] = get_next_line(fd);
	// printf("%s\n", map[5]);
	// map[6] = get_next_line(fd);
	// printf("%s\n", map[6]);
	// map[7] = get_next_line(fd);
	// printf("%s\n", map[7]);
	return (0);
}