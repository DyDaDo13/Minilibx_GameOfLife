#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <X11/extensions/XShm.h>
#include <X11/XKBlib.h>

typedef struct s_data
{
	void			*mlx;
	void			*win;
}t_data;
