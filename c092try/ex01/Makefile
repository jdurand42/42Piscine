# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdurand <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 18:35:31 by jdurand           #+#    #+#              #
#    Updated: 2019/06/25 03:17:45 by jdurand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

PATH	=	srcs/

SRCS	=	$(PATH)ft_putchar.c $(PATH)ft_swap.c $(PATH)ft_putstr.c \
			$(PATH)ft_strlen.c $(PATH)ft_strcmp.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -Iincludes

RM		=	rm -f

all		:	$(NAME)

$(NAME) :	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re	:	fclean	all

.PHONY	:	clean	fclean all
