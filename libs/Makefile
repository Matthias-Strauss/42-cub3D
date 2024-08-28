CC = cc
NAME = libs.a
CFLAGS = 

PRINTFSOURCE = 	./printf/ft_printf.c ./printf/ft_printf_putchar.c ./printf/ft_printf_c.c ./printf/ft_printf_s.c ./printf/ft_printf_percent.c ./printf/ft_printf_i_d.c \
				./printf/ft_printf_u.c ./printf/ft_printf_low_x.c ./printf/ft_printf_up_x.c ./printf/ft_printf_p.c

GET_NEXT_LINESOURCE =	./get_next_line/get_next_line_bonus.c ./get_next_line/get_next_line_utils_bonus.c

LIBFTSOURCE =	./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c	\
				./libft/ft_isprint.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c	\
				./libft/ft_strchr.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c	\
				./libft/ft_strrchr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_calloc.c ./libft/ft_strdup.c ./libft/ft_substr.c	\
				./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c			\
				./libft/ft_putnbr_fd.c ./libft/ft_itoa.c ./libft/ft_strmapi.c ./libft/ft_striteri.c ./libft/ft_split.c

SOURCE = $(PRINTFSOURCE) $(GET_NEXT_LINESOURCE) $(LIBFTSOURCE)

OBJECTS = $(SOURCE:.c=.o)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean:
	@rm -f  $(OBJECTS) $(NAME)

re: fclean all

.PHONY : clean fclean all re
