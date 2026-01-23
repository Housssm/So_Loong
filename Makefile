SRCS = \
		main.c\
		Parsing/parsing.c\
		Parsing/parsing_2.c\
		Parsing/parsing_utils.c\
		Parsing/flood_fill.c\
		utils.c
		
OBJS = ${SRCS:.c=.o}

NAME = so_long

HEADER = so_long.h

LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

GNL_DIR = ./GNL
GNL = ${GNL_DIR}/get_next_line.a

MLX_DIR = ./minilibx-linux
MLX = ${MLX_DIR}/libmlx.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

MLX_FLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm

all: ${NAME}

${NAME}: ${LIBFT} ${GNL} ${MLX} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${GNL} ${LIBFT} ${MLX_FLAGS} -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}

${GNL}: ${LIBFT}
	make -C ${GNL_DIR}

${MLX}:
	make -C ${MLX_DIR}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I${LIBFT_DIR} -I${GNL_DIR} -I${MLX_DIR} -c $< -o $@


clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean
	make -C ${GNL_DIR} clean
	make -C ${MLX_DIR} clean

fclean: clean
	rm -f ${NAME}
	rm -f a.out
	make -C ${LIBFT_DIR} fclean
	make -C ${GNL_DIR} fclean
	make -C ${GNL_DIR} fclean

re: fclean all

.PHONY: all clean fclean re