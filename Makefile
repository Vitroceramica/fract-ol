# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonmar <antonmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 11:53:40 by antonmar          #+#    #+#              #
#    Updated: 2021/08/01 18:19:03 by antonmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -I./
FILES = src/bonus_colors.c \
		src/color_utils.c \
		src/minilibx_utils.c \
		src/fractol_utils.c \
		src/julia.c \
		src/mandelbrot.c
MAIN = fractol.c
MINILIBX = minilibx

all:
	$(MAKE) -C ./$(MINILIBX)
	cp ./$(MINILIBX)/libmlx.dylib ./
	$(CC) $(FLAGS) $(FILES) libmlx.dylib $(MAIN) -o $(NAME)

clean:
		rm -f $(NAME)
		$(MAKE) -C ./$(MINILIBX) clean

fclean: clean
		rm -f libmlx.dylib

re: fclean all

so:		
		gcc -shared -o $(SONAME) -fPIC $(FILES) $(FILES_BONUS)

.PHONY: all clean fclean re bonus