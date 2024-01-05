#include "../inc/life_game.h"

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_map	*ft_lstlast(t_map *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_map	*ft_lstnew(void *content)
{
	t_map	*newnode;

	newnode = malloc(sizeof(t_map));
	if (newnode == NULL)
		return (NULL);
	newnode->map_line = content;
	newnode->next = NULL;
	return (newnode);
}

int	ft_lstsize(t_map *lst)
{
	int		i;
	t_map	*node;

	i = 0;
	node = lst;
	while (node != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}
