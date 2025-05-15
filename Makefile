
CC = cc

# Flagi do kompilacji MLX
CFLAGS = -I./minilibx-linux -O3 -g

# Flagi do linkowania MLX
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

# Nazwa dla so longa, całej tej gry benc
EXEC = so_long

# Lista plików źródłowych
SRC = main.c keyboard_input.c manage_window.c error_handler.c map_parser.c map_checker.c render.c char_movement.c flood_fill.c map_validation.c

# Tworzenie NAZW plikow obiektowych (na podstawie plików .c)
OBJ = $(SRC:.c=.o)

#Linkowanie biblioteki libft
LIBFT = libft

LIBFTL = $(LIBFT)/libft.a

# Deafult
all: $(EXEC)
	
$(LIBFTL):
	@make -C $(LIBFT)/

# Kompilacja plików .c do plików obiektowych
%.o: %.c | $(LIBFTL)
	$(CC) $(CFLAGS) -c $< -o $@ 

# Linkowanie plików obiektowych z biblioteką minilibx i innymi bibliotekami
$(EXEC): $(OBJ) | $(LIBFTL)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS) -L -l $(LIBFTL)

# Usuwanie plików obiektowych
clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT)

# To samo co clean + plik wykonawczy
fclean: clean
	rm -f $(EXEC)
	@make fclean -C $(LIBFT)

# stworz od nowa ze wszystkim
re: fclean all

