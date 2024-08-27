CC = cc
NAME = cub3d
CFLAGS = -Wall -Werror -Wextra -O3 -ffast-math -fsanitize=address -g
LIBMLX = MLX42
USER = $(shell whoami)
LEAKSANITIZER = -L"/$(PWD)/LeakSanitizer" -llsan
MLXFLAGS = $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SOURCE	 = 	main.c

OBJECTS = $(SOURCE:.c=.o)

all : libmlx LeakSanitizer $(NAME)

$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS) -o $(NAME) $(LEAKSANITIZER)

libmlx:
		@if [ ! -d $(LIBMLX) ]; then git clone https://github.com/codam-coding-college/MLX42.git ; fi
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

LeakSanitizer:
		@if [ ! -d LeakSanitizer/liblsan.dzlib ]; then git clone https://github.com/mhahnFr/LeakSanitizer.git ; fi
		@cd LeakSanitizer && make

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f  $(OBJECTS) $(NAME)
	@rm -rf $(LIBMLX)
	@rm -rf LeakSanitizer

re: fclean all

.PHONY : all, clean, fclean, re, libmlx
