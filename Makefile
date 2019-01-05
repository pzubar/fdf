# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pzubar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 11:24:15 by pzubar            #+#    #+#              #
#    Updated: 2018/02/23 11:24:18 by pzubar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = fdf_dealkeys.c fdf_help.c fdf_print.c fdf_read.c
OBJ =  $(SRC:.c=.o)

%.o: %.c
	@gcc -c $? -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) -I /usr/local/include $(SRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit libft/libft.a
	@echo "FdF is ready to use"

clean:
	@/bin/rm -f *.o
	@/bin/rm -f libft/*.o
	@echo "Object files were successfully removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a
	@echo "FdF was successfully removed"

re: fclean all
	@echo "The project was successfully recompiled"
