NAME	= RESIZER

FUNC	= resizer.c

OBJS_DIR	=	objs/
SRCS_DIR	=	src/
MLX_DIR		=	minilibx-linux/

MLX		=	libmlx.a

OBJS	= $(addprefix $(OBJS_DIR), $(FUNC:.c=.o))
SRCS	= $(addprefix $(SRCS_DIR), $(FUNC))
MLXS	= $(addprefix $(MLX_DIR), $(MLX))

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I.
MLX_FLAGS	= -lX11 -lXext


all: $(NAME)


make_OBJS_DIR	:
	@mkdir -p $(OBJS_DIR)


clean:
	@$(RM) $(OBJS_DIR)
	@make -s -C $(MLX_DIR) clean

fclean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(NAME)
	@make -s -C $(MLX_DIR) clean


fclean_re:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(NAME)
	@make -s -C $(MLX_DIR) clean

re:			fclean_re $(NAME)

$(NAME):	make_OBJS_DIR $(OBJS)
	@make -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXS) $(MLX_FLAGS)
$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@