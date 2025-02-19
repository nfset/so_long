# Zmienna kompilatora
CC = gcc

# Flagi kompilatora
CFLAGS = -I./minilibx-linux -O3 -g

# Flagi linkera
LDFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd

# Nazwa pliku wykonywalnego
EXEC = main_window

# Pliki obiektowe
OBJ = main.o

# Domyślna reguła
all: $(EXEC)

# Kompilacja pliku main.c do pliku obiektowego
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Linkowanie pliku obiektowego z biblioteką minilibx i innymi bibliotekami
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

# Usuwanie plików obiektowych i wykonawczych
clean:
	rm -f $(OBJ)

# Usuwanie plików wykonawczych
fclean: clean
	rm -f $(EXEC)

# Reguła do wykonania kompilacji i czyszczenia
re: fclean all
