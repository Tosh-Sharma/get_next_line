NAME ?= get_next_line.a
CC ?= gcc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10
SRCS = 	get_next_line.c \
		get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

BONUS =	get_next_line_bonus.c \
		get_next_line_utils_bonus.c

BONUS_OBJS = $(BONUS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

bonus:	${OBJS} ${BONUS_OBJS}
	ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}

%.o: %.c
	${CC} ${CFLAGS} -o ${@} -c ${@:.o=.c}

re: fclean all

fclean: clean
	rm -f ${NAME}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

.PHONY: clean fclean re all
