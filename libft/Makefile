CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = count_nb_nb.c ft_printf.c ft_memset.c ft_strlcpy.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
ft_strdup.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_striteri.c ft_strmapi.c ft_strjoin.c \
ft_strtrim.c ft_itoa.c ft_putstr_fd.c  ft_putendl_fd.c  ft_putnbr_fd.c ft_calloc.c ft_split.c ft_substr.c \
ft_putchar_fd.c get_next_line_bonus.c get_next_line_bonus_no_nl.c get_next_line_utils_bonus.c ft_putadrrbase.c ft_putnbr_base.c \
ft_putinbr.c ft_strcmp.c ft_putchar.c ft_putstr.c print_split.c ft_tablen.c ft_strnlen.c ft_strndup.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_atol.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)
BONUS_OOBJ = $(BONUS_SRCS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus: $(NAME) $(BONUS_OOBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OOBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
