
CC = cc

# Flagi do kompilacji MLX
CFLAGS = -I./minilibx-linux -O3 -g

# Flagi do linkowania MLX
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

# Nazwa dla so longa, całej tej gry benc
EXEC = so_long

# Lista plików źródłowych
SRC = main.c keyboard_input.c

# Tworzenie NAZW plikow obiektowych (na podstawie plików .c)
OBJ = $(SRC:.c=.o)

# Deafult
all: $(EXEC)

# Kompilacja plików .c do plików obiektowych
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linkowanie plików obiektowych z biblioteką minilibx i innymi bibliotekami
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Usuwanie plików obiektowych
clean:
	rm -f $(OBJ)

# To samo co clean + plik wykonawczy
fclean: clean
	rm -f $(EXEC)

# stworz od nowa ze wszystkim
re: fclean all

