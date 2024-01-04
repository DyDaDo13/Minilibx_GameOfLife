#include "../inc/life_game.h"

void	init_images(t_data *data)
{
	int	x = 0;
	int	y = 0;
	data->sprites.full.image = mlx_xpm_file_to_image(data->mlx, "sprites/full.xpm", &x, &y);
	data->sprites.full.image_pix = mlx_get_data_addr(data->mlx, &data->sprites.full.bits_per, &data->sprites.full.line_len, &data->sprites.full.endian);
	data->sprites.empty.image = mlx_xpm_file_to_image(data->mlx, "sprites/empty.xpm", &x, &y);
	data->sprites.empty.image_pix = mlx_get_data_addr(data->mlx, &data->sprites.empty.bits_per, &data->sprites.empty.line_len, &data->sprites.empty.endian);
}