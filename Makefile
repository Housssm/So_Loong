SRCS = \
		Src/main.c\
		Src/parsing.c\
		Src/parsing_2.c\
		Src/parsing_utils.c\
		Src/flood_fill.c\
		Src/window_management.c\
		Src/game_cleaning.c\
		Src/mouvements.c\
		Src/utils.c
		
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
	@${CC} ${CFLAGS} ${OBJS} ${GNL} ${LIBFT} ${MLX_FLAGS} -o ${NAME}

${LIBFT}:
	@make -sC ${LIBFT_DIR}

${GNL}: ${LIBFT}
	@make -sC ${GNL_DIR}

${MLX}:
	@make -sC ${MLX_DIR}

%.o: %.c ${HEADER}
	@${CC} ${CFLAGS} -I${LIBFT_DIR} -I${GNL_DIR} -I${MLX_DIR} -c $< -o $@


clean:
	@rm -f ${OBJS}
	@make -sC ${LIBFT_DIR} clean
	@make -sC ${GNL_DIR} clean
	@make -sC ${MLX_DIR} clean

fclean: clean
	@rm -f ${NAME}
	@rm -f a.out
	@make -sC ${LIBFT_DIR} fclean
	@make -sC ${GNL_DIR} fclean
	@make -sC ${GNL_DIR} fclean

re: fclean all

.PHONY: all clean fclean re