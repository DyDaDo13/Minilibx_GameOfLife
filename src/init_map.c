#include "../inc/life_game.h"

t_map	*init_map_struct(int fd)
{
	t_map	*lst;								// initialize the lst with "t_map struct"
	t_map	*newnode;							// initialize the newnode with "t_map struct"
	t_map	*start;								// initialize the start with "t_map struct"

	lst = malloc(sizeof(t_map));				// malloc lst
	if (!lst)									// check the malloc
		return (NULL);
	lst->map_line = get_next_line(fd);			// get the first line with get_next_line and put inside "lst->map_line"
	lst->next = NULL;							// set the next pointer of lst to "NULL"
	start = lst;								// set a pointer to the start of the chained list
	while (lst->map_line)						// while lst->map_line pointer exist
	{
		newnode = ft_lstnew(get_next_line(fd));	// set a newlist with ft_lstnew and get the next line with get_next_line and put it in newnode
		lst->next = newnode;					// set the next node of lst to newnode
		lst = lst->next;						// go to the next node
	}
	return (start);
}

void	remove_newlines(t_data data)
{
	int	i;										// initialize i
	int	j;										// initialize j

	i = 0;										// set i to 0
	j = 0;										// set j to 0
	while (data.map[i])
	{
		while (data.map[i][j++])
		{
			if (data.map[i][j] == '\n')
				data.map[i][j] = '\0';			// replace '\n' by '\0'
		}
		j = 0;
		i++;
	}
}

char	**init_map(int fd, t_data *data)
{
	int		i;									// initialize a index "i"				
	t_map	*cpy;								// initialize copy with "t_map struct"

	data->map_char = init_map_struct(fd);		// initialize the chained list in "data->map_char"
	cpy = data->map_char;						// set a copy of data->map_char
	i = ft_lstsize(data->map_char);				// define the size of i by the lst size with ft_lstsize
	data->map_height = i;						// define data->map_height to i
	data->map = malloc(sizeof(char *) * i);		// malloc the data->map with i value
	if (!data->map)								// check malloc
		return (NULL);
	i = 0;										// set i to 0
	while (cpy)									// while cpy exist
	{
		data->map[i] = cpy->map_line;			// define data->map[i] to cpy->map_line
		i++;
		cpy = cpy->next;						// go to the next pointer of cpy
	}
	free_list(&data->map_char);					// free all the list
	remove_newlines(*data);						// remove all the newline get by get_next_line
	map_size_x_y(data);							// get the size of x and y of the map
	return (data->map);
}

void	map_size_x_y(t_data *data)
{
	int		x;									// initialize x
	int		y = 0;								// initialize y and set to 0

	while(data->map[y])
	{
		x = 0;									// set x to 0
		while(data->map[y][x])
			x++;
		y++;
	}
	data->map_height = y;						// set data->map_height to y
	data->map_width = x;						// set data->map_width to x
}
