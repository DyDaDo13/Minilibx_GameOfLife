
#include "../inc/resizer.h"

static int     ft_atoi(const char *nptr)
{
        char    *str;
        int             i;
        int             sign;
        int             nb;

        i = 0;
        nb = 0;
        sign = 1;
        str = (char *)nptr;
        while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        sign *= (-1);
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
                nb = nb * 10 + (str[i] - 48);
                i++;
        }
        nb = nb * sign;
        return (nb);
}

static void	resize1(char *path, int sizex, int sizey, int format)
{
	int	fd = open(path, O_WRONLY | O_TRUNC);
	int	i = 0;
	int	j = 0;
	int	x;
	int	y;

	x = sizex / format;
	y = sizey / format;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			write(fd, "0", 1);
			i++;
		}
		if (j < y)
			write(fd, "\n", 1);
		else
			write(fd, "\0", 1);
		j++;
	}
	close(fd);
}

static void	resize2(char *path, int format, t_data *data)
{
	int	fd = open(path, O_WRONLY | O_TRUNC);
	int	x = 0;
	int	y = 0;
	int	i = 0;
	int	j = 0;

	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &x, &y);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	x /= format;
	y /= format;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			write(fd, "0", 1);
			i++;
		}
		if (j < y)
			write(fd, "\n", 1);
		else
			write(fd, "\0", 1);
		j++;
	}
	close(fd);
}

int	main(int ac, char **av)
{
	if (ac == 5)
		resize1(av[1], ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]));
	else if (ac == 3)
	{
		t_data	data;
		resize2(av[1], ft_atoi(av[2]), &data);
	}
	else
		printf("Error : Try [./a.out 'path/file' sizex sizey format]");
	return (0);
}