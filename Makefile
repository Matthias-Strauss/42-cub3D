# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 14:50:16 by mstrauss          #+#    #+#              #
#    Updated: 2024/10/20 02:53:11 by kklockow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D

CC				= cc
CFLAGS			= -g -fsanitize=address -Wall -Werror -Wextra -Ofast -ffast-math -march=native -mtune=native -funroll-loops
#-fsanitize=address -Wall -Werror -Wextra

INC				= -Iincludes/
LIBMLX			= MLX42

MLXFLAGS		= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit #-ldl -lglfw -pthread -lm

SRC	 = 	main.c							\
		init.c							\
		parser.c						\
		parse_basic.c					\
		parse_copy_map.c				\
		parse_map.c						\
		parse_set_types.c				\
		parse_utils.c					\
		parse_get_map_layout.c			\
		parse_check_map_layout.c		\
		parse_get_missing_information.c	\
		parse_check_for_garbage.c		\
		parse_convert_colors.c			\
		game.c							\
		game_key_hooks.c				\
		game_wasd_keys.c				\
		game_arrow_keys.c				\
		game_loop_hooks.c				\
		game_minimap.c					\
		game_set_player_data.c			\
		rays.c							\
		ray_horizontal.c				\
		ray_vertical.c					\
		draw_line.c						\
		free.c							\
		error.c

SRC_DIR		= ./src
OBJ_DIR		= ./objs
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: mlx $(NAME)

$(NAME): $(OBJS)
	@cd libft && make
	@$(CC) $(OBJS) $(CFLAGS) $(INC) $(MLXFLAGS) libft/libft.a -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

mlx:
	@if [ ! -d $(LIBMLX) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) && \
		cd $(LIBMLX) && \
		git checkout 26fdbd950fd3a4d035fa55af9c02112ffcd4608c; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build -DCMAKE_C_FLAGS="-Ofast -ffast-math -march=native -mtune=native -funroll-loops" && make -C $(LIBMLX)/build -j4


clean:
	@rm -rf $(OBJ_DIR)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	# @rm -rf $(LIBMLX)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re mlx