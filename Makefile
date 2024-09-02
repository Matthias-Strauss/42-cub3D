CC = cc
NAME = cub3D
CFLAGS = -Wall -Werror -Wextra -O3 -ffast-math -g
#-fsanitize=address
LIBMLX = MLX42
USER = $(shell whoami)
LEAKSANITIZER = -L"/$(PWD)/LeakSanitizer" -llsan
MLXFLAGS = $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

SOURCE	 = 	main.c src/init/init.c src/parser/parser.c src/parser/parse_basic.c			\
			src/parser/parse_copy_map.c	src/parser/parse_map.c src/free/free.c			\
			src/parser/parse_set_types.c src/parser/parse_utils.c src/error/error.c		\
			src/utils/utils.c src/parser/parse_get_map_layout.c							\
			src/parser/parse_check_map_layout.c											\
			src/parser/parse_get_missing_information.c									\
			src/parser/parse_check_for_garbage.c										\

OBJECTS = $(SOURCE:.c=.o)

all : libmlx $(NAME)
#LeakSanitizer
$(NAME) : $(OBJECTS)
	@cd libs && make
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJECTS) libs/libs.a -o $(NAME)
#$(LEAKSANITIZER)

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
	@cd libs && make fclean

re: fclean all

.PHONY : all, clean, fclean, re, libmlx
