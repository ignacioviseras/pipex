# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 19:57:48 by igvisera          #+#    #+#              #
#    Updated: 2024/02/13 20:56:21 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	utils.a
CFLAGS			=	-Wall -Wextra -Werror -g 
# CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address

PATH_BASICS 	=	./basics/
PATH_PRINTF 	=	./printf/
BASICS   	  	=	$(addprefix $(PATH_BASICS), $(BASICS_SRC))
PRINTF	     	=	$(addprefix $(PATH_PRINTF), $(PRINTF_SRC))

#carpeta utils
SRCS			=	free_all.c \
					split_formated.c \

# #carpeta basics
BASICS_SRC		=	ft_strlen.c \
					ft_strchr.c \
					ft_strlcpy.c \
					ft_substr.c \
					ft_strdup.c \
					ft_strncmp.c \
					ft_split.c \
					ft_calloc.c \
					ft_bzero.c \
					ft_memset.c \
					ft_strjoin.c \
					ft_strlcat.c \

#carpeta print
PRINTF_SRC		=	ft_printf.c \
					ft_printNumbers.c \
					ft_printText.c \


OBJS			=	${SRCS:.c=.o} \
					${PRINTF:.c=.o} \
					${BASICS:.c=.o} \
					

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re