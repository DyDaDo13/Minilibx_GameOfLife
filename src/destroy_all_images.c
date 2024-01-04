#include "../inc/life_game.h"

void	destroy_all_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprites.empty.image);
	mlx_destroy_image(data->mlx, data->sprites.full.image);
}