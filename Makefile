CC=cc 
NAME=push_swap
GFLAGS=-Wall -Wextra -Werror
SRCS= ${wildcard *.c}
SRCS_OBJS = ${SRCS:.c=.o}

%.o:%.c
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}: ${SRCS_OBJS}
	${CC} ${GFLAGS} ${SRCS_OBJS} -o ${NAME}

clean:
	rm -rf ${SRCS_OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean ${NAME}

all: re

run:
	./${NAME} 1 2 3 4 5 6

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}