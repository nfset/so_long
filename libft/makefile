NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

MANDATORY: \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c
BONUS: \

OBJ: $(MANDATORY:.c=.o)
BOBJ: $(BONUS:.c=.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

bonus: $(OBJ) $(BOBJ)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?
clean:
	rm -f $(OBJ) $(BOBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all


