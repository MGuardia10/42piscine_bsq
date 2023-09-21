NAME	= bsq
FILES	= main.c ftlib.c validate.c validate_stdin.c find_square.c initial_matrix.c binary_matrix.c numeric_square.c free_matrix.c
OBJS	= ${FILES:.c=.o}
HEADER	= ftlib.h
CC		= cc
FLAGS	= -Wall -Werror -Wextra
RM		= rm -f

${NAME}:	${FILES}
					${CC} -c ${FLAGS} ${FILES}
					${CC} ${FLAGS} -o ${NAME} ${OBJS} -I ${HEADER}

all:		${NAME}

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:					fclean ${NAME}

.PHONY:		clean
					fclean
					all
					re
