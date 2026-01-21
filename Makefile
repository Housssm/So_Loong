SRCS = \
		main.c\
		Parsing/parsing.c\
		Parsing/parsing_2.c\
		Parsing/parsing_utils.c\
		utils.c
		
OBJS = ${SRCS:.c=.o}

NAME = so_long

HEADER = so_long.h

LIBFT_DIR = ./libft
LIBFT = ${LIBFT_DIR}/libft.a

GNL_DIR = ./GNL
GNL = ${GNL_DIR}/get_next_line.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

all: ${NAME}

${NAME}: ${LIBFT} ${GNL} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${GNL} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ${LIBFT_DIR}

${GNL}: ${LIBFT}
	make -C ${GNL_DIR}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -I${LIBFT_DIR} -I${GNL_DIR} -c $< -o $@

clean:
	rm -f ${OBJS}
	make -C ${LIBFT_DIR} clean
	make -C ${GNL_DIR} clean

fclean: clean
	rm -f ${NAME}
	rm -f a.out
	make -C ${LIBFT_DIR} fclean
	make -C ${GNL_DIR} fclean

re: fclean all

.PHONY: all clean fclean re