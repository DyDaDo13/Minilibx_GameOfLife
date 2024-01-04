
#include "resizer.h"

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

static void	resize1(char *path, int sizex, int sizey, int format, t_data *data)
{
	int	fd = open("path", O_WRONLY | O_TRUNC);
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
			write(fd, "1", 1);
			i++;
		}
		if (j < y)
			write(fd, "\n", 1);
		else
			write(fd, "\0", 1);
		j++;
	}
}

// static void	resize2(char *path, int format, t_data *data)
// {
// 	int	fd = open("path", O_WRONLY | O_TRUNC);
// 	int	x;
// 	int	y;
// 	int	i = 0;
// 	int	j = 0;

// 	mlx_get_screen_size(data->mlx, &x, &y);
// 	x /= format;
// 	y /= format;
// 	while (j < y)
// 	{
// 		i = 0;
// 		while (i < x)
// 		{
// 			write(fd, "0", 1);
// 			i++;
// 		}
// 		if (j < y)
// 			write(fd, "\n", 1);
// 		else
// 			write(fd, "\0", 1);
// 		j++;
// 	}
// }

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 5)
		resize1(av[1], ft_atoi(av[2]), ft_atoi(av[3]), ft_atoi(av[4]), data);
	// else if (ac == 3)
	// 	resize2(av[1], ft_atoi(av[2]), data);
	else
		printf("Error : Try [./a.out 'path/file' sizex sizey format]");
	return (0);
}