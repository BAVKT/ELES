# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/08 16:11:48 by vmercadi          #+#    #+#              #
#    Updated: 2017/08/19 19:02:41 by vmercadi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = srcs/main.c srcs/utils.c srcs/init.c srcs/opt1.c srcs/error.c \
		srcs/check.c srcs/optl.c srcs/bonus.c srcs/clean.c srcs/opt_t.c \

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

SRCO = $(SRC:%.c=%.o)

LIB = libft/libft.a

.PHONY: all re clean

all: $(NAME)

$(NAME):$(SRCO)
	@make -C libft/
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INCLUDES)

clean:
	@rm -rf $(SRCO)
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft/

ultra: all clean

re: fclean all
