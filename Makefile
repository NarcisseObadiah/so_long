# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/02 03:51:00 by mobadiah          #+#    #+#              #
#    Updated: 2023/09/11 19:40:30 by mobadiah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long
SRC			:=	SRC/MAP_VALIDATION/map_parsing.c SRC/MAP_VALIDATION/map_checking_utils.c SRC/MAP_VALIDATION/map_checking_utils2.c  SRC/utils.c  SRC/MAP_VALIDATION/check_path.c  SRC/init_struct.c SRC/get_coordinate.c  SRC/load_player.c SRC/load_images.c SRC/so_long.c SRC/rend_map.c SRC/moves.c SRC/direction.c
# LIBMLX		:= ./MLX42
LIBFT		:= ./libft
OBJ			:= $(SRC:.c=.o)
CC			:=	cc
CFLAGS		:= -Wall -Werror -Wextra# -fsanitize=address
# HEADERS	:= -Iinclude -lglfw 

all: clone_MLX $(NAME) 

clone_MLX:
	@if [ -e "MLX42" ]; then \
		echo "up to date"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42; \
		cmake -B build; \
		make -C build -j4; \
		cd MLX42; cmake .; \
	fi

$(NAME): $(OBJ) $(LIBFT)
	make -C ./libft
	make -C ./MLX42
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a MLX42/libmlx42.a -lglfw -L ~/.brew/cellar/glfw/3.3.8/lib -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT)


clean:
	make clean -C $(LIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf libft/libft.a
	@rm -rf ./MLX42
	@rm -f $(NAME)

re: fclean all

.PHONY: so_long, build_mlx, build_libft, all, clean, fclean, re