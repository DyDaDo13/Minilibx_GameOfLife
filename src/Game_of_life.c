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
	data->mlx = mlx_init();						// initialize the pointer mlx
	data->win = mlx_new_window(data->mlx, (data->map_width * 16), (data->map_height * 16), "GAME OF LIFE"); //create a new window
	init_images(data);							// initialize all images
	draw_map(data->map, data);					// draw the map
	mlx_string_put(data->mlx, data->win, 6, 12, -200, ft_itoa(data->gen));
	mlx_string_put(data->mlx, data->win, 6, 28, 2000, ft_itoa(data->rule));
	mlx_hook(data->win, 3, (1L << 0) + (1L << 1), ft_key_check, data);
	mlx_hook(data->win, ButtonPress, (1L << 2), mouse_hook, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;								// initialize the structure "data"
	int		fd;									// initialize the file descriptor "fd"
	
	data = malloc(sizeof(t_data));				// malloc the data
	if (ac == 2)								// if the number of arguments are equals to 2
		data->rule = ft_atoi(av[1]);			// data->rule equals the secont argument "number"
	else
		data->rule = 3;
	fd = open("map/map.txt", O_RDONLY);			// open the fd with "0_RDONLY" flag
	data->map = init_map(fd, data);				// put all the map (fd) inside a "char **"
	ft_display(data);							// start the display of the game
	return (0);
}
