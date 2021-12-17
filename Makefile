# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 10:46:59 by mapontil          #+#    #+#              #
#    Updated: 2021/12/15 10:27:43 by mapontil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			pipex.c \
			utils.c \
			parsing.c \
			ft_split.c
OBJS	=	$(addprefix srcs/, ${SRCS:.c=.o})
HEAD	=	includes/pipex.h
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	pipex

%.o:		%.c ${HEAD}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}
all:		${NAME}
clean:
			rm -f ${OBJS}
fclean:		clean
			rm -f ${NAME}
re:			fclean all
.PHONY:		all clean fclean re