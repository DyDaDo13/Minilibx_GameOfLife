/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:35:32 by dydado13          #+#    #+#             */
/*   Updated: 2024/01/04 09:28:35 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/life_game.h"

void	free_map(t_data *data)
{
	int		i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
}

void	free_list(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while ((*map))
	{
		tmp = (*map)->next;
		free((*map));
		(*map) = tmp;
	}
}

void	free_all(t_data *data)
{
	if (data->map)
	{
		free_map(data);
		free(data->map);
	}
}
