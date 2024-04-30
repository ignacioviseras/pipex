# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 20:50:53 by igvisera          #+#    #+#              #
#    Updated: 2024/04/06 14:40:18 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
# CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -O3
# CFLAGS	=	-Wall -Wextra -Werror -g -O3
CFLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -O3

UTILS_A		=	utils.a
UTILS_SRC 	=	./utils/
UTILS_OBJS	=	$(addprefix $(UTILS_SRC), *.o)
UTILS     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))

SRCS	=	pipex.c \
			validator.c \
			# pipex_utils.c \

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(UTILS) $(OBJS)
	gcc $(CFLAGS) $(OBJS) -I ./pipex.h $(UTILS) -o $(NAME)

$(UTILS):
	$(MAKE) -C $(UTILS_SRC)

clean:
	rm -f $(OBJS) $(UTILS_OBJS)
	$(MAKE) -C $(UTILS_SRC) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(UTILS_SRC) fclean

re: fclean all

.PHONY: all clean fclean re