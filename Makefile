CC 			:= 	cc 
NAME 		:= 	push_swap
ASSERT_NAME := 	assertions/assertion
ALGO_NAME 	:= 	sort_algo/sort_algo
GFLAGS 		:=	-Wall -Wextra -Werror -g
SRCS 		:= 	${wildcard *.c}
SRCS_ASSERT	:=	${wildcard assertions/*.c}
SRCS_ALGO	:=	${wildcard sort_algo/*.c}
SRCS_OBJS 	:=	${SRCS:.c=.o}
ASSERT_OBJS	:=	${SRCS_ASSERT:.c=.o} ${SRCS_OBJS}
ALGO_OBJS	:=	${SRCS_ALGO:.c=.o}
PS_ARGS		:=	1 2 3 4 5 6 7 8

%.o:%.c
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}:	${SRCS_OBJS}
		${CC} ${GFLAGS} ${SRCS_OBJS} -Llibft_v2 -lft -o ${NAME}

as: 	${ASSERT_OBJS}
		${CC} ${GFLAGS} ${ASSERT_OBJS} -o ${ASSERT_NAME}
		./${ASSERT_NAME}

asm: 	${ASSERT_OBJS}
		${CC} ${GFLAGS} ${ASSERT_OBJS} -o ${ASSERT_NAME}
		leaks --atExit -- ./${ASSERT_NAME} ${PS_ARGS}

algo:	${ALGO_OBJS}
		${CC} ${GFLAGS} ${ALGO_OBJS} -o ${ALGO_NAME}
		./${ALGO_NAME}

clean:
	rm -rf ${SRCS_OBJS} ${ASSERT_OBJS} ${ALGO_OBJS}

fclean:	clean
	rm -rf ${NAME} ${ASSERT_NAME} ${ALGO_NAME}

re:	fclean ${NAME}

all: re

run:
	./${NAME} 1 2 3 4 5 6

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}

lib:
	cd libft_v2 && make re