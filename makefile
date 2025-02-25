NAME		=	so_long
NAME_BONUS	=	so_long_bonus

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra -g3
LIBFT		=	./libs
LIBMLX		=	./MLX42

LIBS		=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HEADERS		=	-I $(libs)/Includes
HEADER_BONUS=	-I $(libs)/Includes -I $(LIBMLX)/build

SRCS		=	./src/so_long.c \
				./src/handle_map.c \
				./src/handle_erros.c \
				./src/handle_inits.c \
				./src/handle_render.c \
				./src/handle_player.c \
				./src/handle_moves.c \
				./src/utils.c \
				./src/handle_flood_fill.c \
				./src/handle_clear.c

SRCS_BONUS		=	./bonus/so_long_bonus.c \
				./bonus/handle_map_bonus.c \
				./bonus/handle_erros_bonus.c \
				./bonus/handle_inits_bonus.c \
				./bonus/handle_render_bonus.c \
				./bonus/handle_player_bonus.c \
				./bonus/handle_moves_bonus.c \
				./bonus/handle_enemy_bonus.c \
				./bonus/utils_bonus.c \
				./bonus/handle_flood_fill_bonus.c \
				./bonus/handle_clear_bonus.c

OBJS			=	${SRCS:.c=.o}
OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

all: libmlx libft ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o:%.c
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

bonus: libmlx libft ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS_BONUS) -o $(NAME_BONUS)

clean:
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_BONUS}
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf ${NAME} ${NAME_BONUS}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all bonus

.PHONY: all clean fclean re libft bonus