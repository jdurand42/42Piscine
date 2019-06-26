# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdoublet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 09:33:54 by cdoublet          #+#    #+#              #
#    Updated: 2019/06/26 22:17:49 by cdoublet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = 	main.c create_tmp_map.c init_params.c tools1.c \
		check_map.c create_map.c solve_map.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
