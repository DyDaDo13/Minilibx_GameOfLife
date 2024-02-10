#────────────────────────────╮
NAME	= Gameoflife
#────────────────────────────╯

#---------	FUNCTIONS -----------
#───────────────────────────────╲
FUNC	= destroy_all_images.c \
free_all.c get_next_line.c \
get_next_line_utils.c \
init_images.c init_map.c \
lst_functions.c Game_of_life.c \
draw.c get_m_x_y.c \
algorithm.c hooks.c reset.c \
print_map.c map_cpy.c ft_itoa.c \
presets.c ft_atoi.c time.c save_map.c \
#───────────────────────────────╱

#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃					  PATH 		     			 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━

OBJS_DIR	=	objs/
SRCS_DIR	=	src/
MLX_DIR		=	minilibx-linux/


#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃					   OBJS	 		     		 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━

MLX		=	libmlx.a


#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃					   SRCS	 		     		 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━

OBJS	= $(addprefix $(OBJS_DIR), $(FUNC:.c=.o))
SRCS	= $(addprefix $(SRCS_DIR), $(FUNC))
MLXS	= $(addprefix $(MLX_DIR), $(MLX))


#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃					  Flags 		     		 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
INCLUDE		= -I.
MLX_FLAGS	= -lX11 -lXext


#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃				   	  RULES 		     		 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━

all:		message message_all $(NAME) message_success


make_OBJS_DIR	:
	@mkdir -p $(OBJS_DIR)


clean:		message message_clean message_mlx
			@echo "$(COLOUR_RED)REMOVING $(MLX)$(NO_COLOUR)"
			@$(RM) $(OBJS_DIR)
			@make -s -C $(MLX_DIR) clean
			@echo "$(COLOUR_OK)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NO_COLOUR)"

fclean:		message message_fclean message_mlx
	@echo "$(COLOUR_RED)REMOVING $(MLX)$(NO_COLOUR)"
			@$(RM) $(OBJS_DIR)
			@$(RM) $(NAME)
			@make -s -C $(MLX_DIR) clean
			@echo "$(COLOUR_OK)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NO_COLOUR)"

fclean_re:	message message_re message_mlx
			@echo "$(COLOUR_RED)REMOVING $(MLX)$(NO_COLOUR)"
			@$(RM) $(OBJS_DIR)
			@$(RM) $(NAME)
			@make -s -C $(MLX_DIR) clean
			@echo "$(COLOUR_OK)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NO_COLOUR)"

re:			message fclean_re $(NAME) message_success

#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃				   COMPILATION		     		 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━

$(NAME):	make_OBJS_DIR $(OBJS)
	@echo "\n$(COLOUR_OK)                               ┏━━━━━━━━━━┓"
	@echo "                               ┃  $(COLOUR_BLUE)libmlx$(COLOUR_OK)  ┃"
	@echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NO_COLOUR)"
	@echo "$(COLOUR_OK)ADDING $(MLX)$(NO_COLOUR)"
	@make -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLXS) $(MLX_FLAGS)
	@echo "$(COLOUR_OK)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NO_COLOUR)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(COLOUR_OK)[✔] $(COLOUR_BLUE)Just compiled $<$ $(NO_COLOUR)"

#┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
#┃				   	  					 MESSAGES 	        					     		 ┃
#┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

message_success:
	@echo "$(COLOUR_OK)┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓$(NO_COLOUR)"
	@echo "$(COLOUR_OK)┃ Compilation Success !!! : Creating $(NAME)	┃$(NO_COLOUR)"
	@echo "$(COLOUR_OK)┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛$(NO_COLOUR)"

message_all:
	@echo "$(COLOUR_OK)[✔] $(COLOUR_RED)all\n$(NO_COLOUR)"

message_clean:
	@echo "$(COLOUR_OK)[✔] $(COLOUR_RED)clean\n$(NO_COLOUR)"

message_fclean:
	@echo "$(COLOUR_OK)[✔] $(COLOUR_RED)fclean\n$(NO_COLOUR)"
	@echo "$(COLOUR_OK)[✔] $(COLOUR_BLUE)Removed - $(NAME)\n$(NO_COLOUR)"

message_re:
	@echo "$(COLOUR_OK)[✔] $(COLOUR_RED)re\n$(NO_COLOUR)"

message_mlx:
	@echo "\n$(COLOUR_OK)                               ┏━━━━━━━━━━┓"
	@echo "                               ┃  $(COLOUR_BLUE)libmlx$(COLOUR_OK)  ┃"
	@echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NO_COLOUR)"

message:
	@printf "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	@printf "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	@printf "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	@printf "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	@printf "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
	@tput cup init
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)███████$(COLOUR_BLACK)████$(COLOUR_GREEN)████████████$(COLOUR_BLACK)████$(COLOUR_GREEN)███████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)█████$(COLOUR_BLACK)██$(COLOUR_GREEN)████$(COLOUR_BLACK)██$(COLOUR_GREEN)████████$(COLOUR_BLACK)██$(COLOUR_GREEN)████$(COLOUR_BLACK)██$(COLOUR_GREEN)█████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)█████████$(COLOUR_BLACK)██████████████$(COLOUR_GREEN)███████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)█████████$(COLOUR_BLACK)██$(COLOUR_RED)██████████$(COLOUR_BLACK)██$(COLOUR_GREEN)███████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)███████████$(COLOUR_BLACK)██$(COLOUR_RED)████████$(COLOUR_BLACK)██$(COLOUR_GREEN)███████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)███████████$(COLOUR_BLACK)██$(COLOUR_RED)████████$(COLOUR_BLACK)██$(COLOUR_GREEN)███████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)█████████████$(COLOUR_BLACK)████████$(COLOUR_GREEN)█████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "$(COLOUR_GREEN)██████████████████████████████████$(NO_COLOUR)"
	@echo "\n\n$(COLOUR_OK)    ...MAKEFILE BY DYDADO13...\n$(NO_COLOUR)"
	@echo "Name	:	$(NAME)"
	@echo "Author	:	dylmarti, Dylan Martinez"
	@echo "Compil	:	$(CC)"
	@echo "Flags	:	-Wall -Werror -Wextra\n"

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

#============ Colours ============

COLOUR_BLUE		= \033[34m
COLOUR_GREEN	= \033[90m
COLOUR_BLACK	= \033[30m
COLOUR_RED		= \033[31m
COLOUR_OK		= \033[32m
COLOUR_BAD		= \033[31m
COLOUR_CYAN		= \033[36m
NO_COLOUR		= \033[0m
