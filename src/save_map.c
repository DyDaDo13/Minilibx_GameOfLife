#include "../inc/life_game.h"

void	print_map_fd(int fd, t_data *data)
{
	int	i = -1;
	int j = -1;

	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			write(fd, &data->map[i][j], 1);
		write(fd, "\n", 1);
	}
}

char	*find_file(void)
{
	int	i = -1;
	char	*file_name;
	
	while (++i < 50)
	{
		file_name = ft_strjoin("file", ft_itoa(i), 0);
		if (access(file_name, F_OK) != 0)
			return (file_name);
		free(file_name);
	}
	return (NULL);
}

int save_map(t_data *data)
{
	char	*file;
	int	fd;

	file = find_file();
	if (file == NULL)
		return (printf("error while save map\n"), 1);
	fd = open(file, O_CREAT | O_WRONLY, 0777);
	print_map_fd(fd, data);
	printf("created %s\n", file);
	return (free(file), 0);
}