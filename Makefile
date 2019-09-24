# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 16:12:18 by ghtouman          #+#    #+#              #
#    Updated: 2019/02/22 10:29:29 by ghtouman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra
IDIR = ./includes/
NAME = fdf
SRC_PATH = ./srcs/
LIB_PATH = ./libft/
LIB = libft/libft.a
MlX_PATH = ./minilibx_macos/
MLX = minilibx_macos/libmlx.a
M.FLAG = -lmlx -framework OpenGL -framework Appkit

FILES =	fdf.c				\
		gen_map.c			\
		error_handler.c		\
		draw.c				\
		fdf_arg.c

SRCS_FILES = $(addprefix srcs/, $(FILES))
OBJ = $(SRCS_FILES:.c=.o)

all:$(NAME)
$(NAME): $(LIB) $(OBJ)
	make -C $(MlX_PATH)
	gcc $(OBJ) $(LIB) -I $(LIB_PATH) $(M.FLAG) $(MLX) -I $(MlX_PATH) -o $(NAME)

%.o: %.c
	gcc -c $(FLAG) $< -o $@ -I$(IDIR)

$(OBJ) : $(IDIR)fdf.h

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)
	make clean -C $(MlX_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	rm -f $(MLX)

re: fclean all

libft/libft.a:
	make -C libft
