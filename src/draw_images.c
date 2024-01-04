/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:22:35 by dylmarti          #+#    #+#             */
/*   Updated: 2024/01/04 09:30:59 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life_game.h"

void	draw_images(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.full.image, data->x, data->y);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->sprites.empty.image, data->x, data->y);
}
