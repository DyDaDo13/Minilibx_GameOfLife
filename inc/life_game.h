#ifndef LIFE_GAME_H
# define LIFE_GAME_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
//# include <sys/mman.h>
//# include <X11/Xlib.h>
//# include <X11/Xutil.h>
//# include <sys/ipc.h>
//# include <sys/shm.h>
//# include <X11/extensions/XShm.h>
//# include <X11/XKBlib.h>

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

typedef struct s_image
{
	void	*image;
	char	*image_pix;
	int		bits_per;
	int		endian;
	int		line_len;
}	t_image;

typedef struct s_sprites
{
	t_image	empty;
	t_image full;
}	t_sprites;

typedef struct s_point
{
	int		x;
	int		y;
}t_point;

typedef struct s_data
{
	char			**map;			// the map
	void			*mlx;			// pointer mlx
	void			*win;			// pointer window
	int				rule;			// the rule of my game "numbers"
	int				i;				// a index i
	int				j;				// a index j
	int				image__posx;	// the pos of the image on the screen
	int				image__posy;
	int				mouse_posx;		// the position of the mnouse
	int				mouse_posy;
	int				bloc_posx;		// the position of a block
	int				bloc_posy;
	int				x;				// index x
	int				y;				// index y
	int				gen;			// generation counter
	int				map_height;		// the height of the map
	int				map_width;		// the width of the map
	t_map			*map_char;
	t_sprites		sprites;
}t_data;

///////// GAME ////////////
int		algorithm(t_data *data);
int		reset(t_data *data);
int		damed_map(t_data *data);
int		random_map(t_data *data);

///////////// LIST FUNCTIONS /////////
int		ft_lstsize(t_map *lst);
t_map	*ft_lstnew(void *content);
t_map	*ft_lstlast(t_map *lst);
void	ft_lstadd_back(t_map **lst, t_map *new);

/////////// DATA ///////////////
void	get_m_x_y(t_data *data, int x, int y);
void	map_size_x_y(t_data *data);

/////////// FREE AND DESTROY ////////////
void	free_map(t_data *data);
void	free_all(t_data *data);
void	free_list(t_map **map);
void	destroy_all_images(t_data *data);
int		ft_stop(t_data *data);

///////////// INIT AND DRAW /////////////
void	draw_map(char **map, t_data *data);
char	**init_map(int fd, t_data *data);
void	init_images(t_data *data);
void	draw_images(char **map, t_data *data, int i, int j);

////////////// HOOKS //////////////
int		mouse_hook(int mc, int x, int y, t_data *data);
int		ft_key_check(int key, t_data *data);

///////////////// OTHERS ////////////////
void	print_map(char **map);
char	**map_cpy(char **map);
char	*ft_itoa(int n);
char	**damed_map2(char **str, char c, char r);
int		ft_atoi(char *nptr);

#endif
