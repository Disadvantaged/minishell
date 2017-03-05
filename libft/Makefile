NAME  = libft.a
FLAGS = -Wall -Werror -Wextra -I./includes
SRC = ft_atoi.c \
	   ft_atoi_base.c \
	   ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isblank.c \
	   ft_isdigit.c \
	   ft_islower.c \
	   ft_isprint.c \
	   ft_isspace.c \
	   ft_isupper.c \
	   ft_itoa.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_nbrlen.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_puterr.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putnstr.c \
	   ft_putnwstr.c \
	   ft_putnstr_fd.c \
	   ft_putnwstr_fd.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_puttab.c \
	   ft_putwchar.c \
	   ft_putwchar_fd.c \
	   ft_putwstr.c \
	   ft_putwstr_fd.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_intcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_strequ.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strndup.c \
	   ft_strnequ.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_unsigned_itoa.c \
	   ft_wstrlen.c \
	   get_next_line.c \
	   ft_printf/ft_printf.c \
	   ft_printf/checker.c \
	   ft_printf/conversion.c \
	   ft_printf/print_unsigned.c \
	   ft_printf/print_int.c \
	   ft_printf/print_unsigned1.c \
	   ft_printf/print_int1.c \
	   ft_printf/print_char.c \
	   ft_printf/print_string.c \
	   ft_printf/print_wchar.c \
	   ft_printf/print_wstring.c \
	   ft_printf/print_adress.c \
	   ft_printf/colors.c \
	   ft_lstlen.c \
	   ft_lstsort.c \
	   ft_lstrev.c \
	   ft_lstaddlast.c
SRCS = $(addprefix src/, $(SRC))
RM = rm -f
MKDIR = @mkdir -p $(@D)
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

obj/%.o: src/%.c
	$(MKDIR)
	@$(CC) $(FLAGS) -c  -o $@ $<

all:	$(NAME)

$(NAME): $(OBJS)
	@ echo -n 'Creating library ... '
	@ ar rc $(NAME) $(OBJS)
	@ ranlib $(NAME)
	@ echo '[done]'

clean:
	@ echo -n 'Removing objects ... '
	@ rm -f $(OBJS)
	@ echo '[done]'

fclean: clean
	@ echo -n 'Removing library ... '
	@ rm -f $(NAME)
	@ echo '[done]'

re: fclean all

.PHONY: all clean fclean re
