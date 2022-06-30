# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sneyt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 09:18:59 by sneyt             #+#    #+#              #
#    Updated: 2022/06/04 09:24:35 by sneyt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		@cd libft && make all
		@gcc -Wall -Wextra -Werror server.c libft/libft.a -o server
		@gcc -Wall -Wextra -Werror client.c libft/libft.a -o client

clean:
		@cd libft && make clean
		@rm -f server
		@rm -f client

fclean:	clean
		@cd libft && make fclean

re:	fclean all
