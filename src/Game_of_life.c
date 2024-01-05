#include "../inc/life_game.h"

int	ft_stop(t_data *data)
{
	return (destroy_all_images(data), mlx_destroy_window(data->mlx, data->win), mlx_destroy_display(data->mlx), free(data->mlx), free_all(data), exit(1), 0);
}

void	ft_display(t_data *data)
{
	data->x = 0;
	data->y = 0;
	data->b_x = 0;
	data->b_y = 0;
	data->gen = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, (data->map_width * 16), (data->map_height * 16), "GAME OF LIFE");
	init_images(data);
	draw_map(data->map, data);
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
	ft_display(data);
	return (0);
}