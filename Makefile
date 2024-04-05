# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 20:50:53 by igvisera          #+#    #+#              #
#    Updated: 2024/04/05 20:55:56 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -O3


SRCS	=	pipex.c \
			pipex_utils.c \

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -I ./fdf.h -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re