#include "../inc/life_game.h"

static int	get_nb_of_digits(long int n)
{
	int	nb;

	nb = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nb++;
		n *= -1;
	}
	while (n >= 10)
	{
		nb++;
		n = n / 10;
	}
	if (n < 10 || n == 0)
		nb++;
	return (nb);
}

static char	*fill_str(char *str, long int n, int nb_dg)
{
	str[nb_dg] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb_dg > 0 && n != 0)
	{
		str[nb_dg - 1] = ((n % 10) + '0');
		n /= 10;
		nb_dg--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nb_dg;

	nb_dg = get_nb_of_digits((long int)n);
	str = malloc(sizeof(char) * nb_dg + 1);
	if (str == NULL)
		return (NULL);
	str = fill_str(str, (long int)n, nb_dg);
	return (str);
}
