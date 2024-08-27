CC = cc
NAME = cub3d
CFLAGS = -Wall -Werror -Wextra -O3 -ffast-math -fsanitize=address -g
LIBMLX = MLX42
USER = $(shell whoami)
LEAKSANITIZER = -L"/$(PWD)/LeakSanitizer" -llsan
MLXFLAGS = $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SOURCE	 = 	main.c

OBJECTS = $(SOURCE:.c=.o)

all : libmlx $(NAME)

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS) -o $(NAME) $(LEAKSANITIZER)

libmlx:
		@if [ ! -d $(LIBMLX)/build ]; then git clone https://github.com/codam-coding-college/MLX42.git ; fi
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


clean:
	@rm -f $(OBJECTS)
	@rm -rf $(LIBMLX)/build

fclean:
	@rm -f  $(OBJECTS) $(NAME)
	@rm -rf $(LIBMLX)/build

re: fclean all

.PHONY : all, clean, fclean, re, libmlx
