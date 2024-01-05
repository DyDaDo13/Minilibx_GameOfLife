#include "../inc/life_game.h"

char	**map_cpy(char **map)
{
	char	**cpy;
	int		x;
	int		y = -1;

	while (map[++y])
	{
		x = 0;
		while(map[y][x])
			x++;
	}
	cpy = malloc(sizeof(char*) * (y + 1));
	cpy[y] = NULL;
	y = 0;
	while (map[y])
	{
		cpy[y] = malloc(sizeof(char) * (x + 1));
		cpy[y][x] = '\0';
		y++;
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			cpy[y][x] = map[y][x];
			x++;
		}
		y++;
	}
	return (cpy);
}
