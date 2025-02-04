NAME		=	so_long

CC			=	cc
FLAGS		=	-Wall -Werror -Wextra
LIBFT		=	./libs
LIBMLX		=	./MLX42

LIBS		=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT)/libft.a

HEADERS		=	-I $(libs)/Includes

SRCS		=	./src/so_long.c \
				./src/handle_map.c \
				./src/handle_erros.c \
				./src/handle_inits.c \
				./src/handle_render.c

OBJS		=	${SRCS:.c=.o}

all: libmlx libft ${NAME}

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@make -C $(LIBFT)

${NAME}: ${OBJS}
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o:%.c
	${CC} ${FLAGS} -o $@ -c $< ${HEADERS}

bonus: libft ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	$(CC) $(OBJS_BONUS) $(LIB) $(HEADERS) -o $(NAME_BONUS)

clean:
	@rm -rf ${OBJS}
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean:	clean
	@rm -rf ${NAME} ${NAME_BONUS}
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all bonus

.PHONY: all clean fclean re libft bonus