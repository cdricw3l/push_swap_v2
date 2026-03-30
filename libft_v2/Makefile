CC=cc
AR=ar -rcs
GFLAGS=-Wall -Wextra -Werror
NAME=libft.a
NAME_ASSERT=assertion/assert_test
SRCS=${wildcard *.c}
SRCS_ASSER= assertion/assertion.c \
			${wildcard *.c}
OBJETS_SRCS=${SRCS:.c=.o}
OBJETS_ASSERT=${SRCS_ASSER:.c=.o}

%.o:%.c
	${CC} -c ${GFLAGS} $^ -o $@

${NAME}: ${OBJETS_SRCS}
	${AR} ${NAME} ${OBJETS_SRCS}

clean:
	rm -f ${OBJETS_SRCS} ${OBJETS_ASSERT}
	rm -rf test*

fclean: clean
	rm -f ${NAME} ${NAME_ASSERT}

re: fclean ${NAME}

as: ${OBJETS_ASSERT} ${OBJETS_SRCS} 
	${CC} ${GFLAGS} ${OBJETS_ASSERT} -o ${NAME_ASSERT}
	./${NAME_ASSERT}

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}