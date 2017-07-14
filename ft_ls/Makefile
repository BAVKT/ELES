# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 16:11:48 by vmercadi          #+#    #+#              #
#    Updated: 2017/07/08 01:03:36 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = srcs/main.c srcs/sort.c srcs/utils.c srcs/init.c srcs/test.c srcs/opt1.c \
		srcs/error.c srcs/check.c srcs/path.c

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

SRCO = $(SRC:%.c=%.o)

INCLUDES = includes

.PHONY: all re clean

all: $(NAME)

$(NAME):
	@make re -C libft/
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

re: fclean all
