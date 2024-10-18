CC = cc
NAME = cub3D
CFLAGS = -g -Wall -Werror -Wextra -I./includes -Ofast -ffast-math -march=native -mtune=native -funroll-loops
#-fsanitize=address -Wall -Werror -Wextra

LIBMLX = MLX42
USER = $(shell whoami)
LEAKSANITIZER = -L"/$(PWD)/LeakSanitizer" -llsan
MLXFLAGS = $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -framework Cocoa -framework OpenGL -framework IOKit #-ldl -lglfw -pthread -lm

SOURCE	 = 	main.c										\
            src/init/init.c								\
            src/parser/parser.c							\
            src/parser/parse_basic.c					\
            src/parser/parse_copy_map.c					\
            src/parser/parse_map.c						\
            src/parser/parse_set_types.c				\
            src/parser/parse_utils.c					\
            src/parser/parse_get_map_layout.c			\
            src/parser/parse_check_map_layout.c			\
            src/parser/parse_get_missing_information.c	\
            src/parser/parse_check_for_garbage.c		\
            src/parser/parse_convert_colors.c			\
            src/game/game.c								\
            src/game/game_key_hooks.c					\
            src/game/game_loop_hooks.c					\
            src/rays/rays.c								\
            src/rays/ray_horizontal.c					\
            src/rays/ray_vertical.c						\
            src/utils/draw_line.c						\
            src/free/free.c								\
            src/error/error.c

OBJ_DIR = ./objs
OBJECTS = $(SOURCE:%.c=$(OBJ_DIR)/%.o)

all : libmlx $(NAME)

$(NAME) : $(OBJECTS)
	@cd libft && make
	@$(CC) $(OBJECTS) $(CFLAGS) $(MLXFLAGS) libft/libft.a -o $(NAME)

objs/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

libmlx:
	@if [ ! -d $(LIBMLX) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) && \
		cd $(LIBMLX) && \
		git checkout 26fdbd950fd3a4d035fa55af9c02112ffcd4608c; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build -DCMAKE_C_FLAGS="-Ofast -ffast-math -march=native -mtune=native -funroll-loops" && make -C $(LIBMLX)/build -j4
	@if [ ! -d $(LIBMLX) ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX) && \
		cd $(LIBMLX) && \
		git checkout 26fdbd950fd3a4d035fa55af9c02112ffcd4608c; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build -DCMAKE_C_FLAGS="-Ofast -ffast-math -march=native -mtune=native -funroll-loops" && make -C $(LIBMLX)/build -j4

clean:
	@rm -rf objs
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(LIBMLX)
	@rm -rf LeakSanitizer
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re libmlx