CC 			:= 	cc 
NAME 		:= 	push_swap
ASSERT_NAME := 	assertions/assertion
GFLAGS 		:=	-Wall -Wextra -Werror
SRCS 		:= 	${wildcard *.c}
SRCS_ASSERT	:=	${wildcard assertions/*.c}
SRCS_OBJS 	:=	${SRCS:.c=.o}
ASSERT_OBJS	:=	${SRCS_ASSERT:.c=.o} ${SRCS_OBJS}
PS_ARGS		:=	1 2 3 4 5 6 7 8

%.o:%.c
	${CC} ${GFLAGS} -c $^ -o $@

${NAME}: ${SRCS_OBJS}
	${CC} ${GFLAGS} ${SRCS_OBJS} -o ${NAME}

as: ${ASSERT_OBJS}
	${CC} ${GFLAGS} ${ASSERT_OBJS} -o ${ASSERT_NAME}
	./${ASSERT_NAME} ${PS_ARGS}

asm: ${ASSERT_OBJS}
	${CC} ${GFLAGS} ${ASSERT_OBJS} -o ${ASSERT_NAME}
	leaks --atExit -- ./${ASSERT_NAME} ${PS_ARGS}

clean:
	rm -rf ${SRCS_OBJS} ${ASSERT_OBJS}

fclean: clean
	rm -rf ${NAME} ${ASSERT_NAME}

re: fclean ${NAME}

all: re

run:
	./${NAME} 1 2 3 4 5 6

git: fclean
	git add .
	git commit -m ${COM}
	git push origin ${shell git branch --show-current}