/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:34:25 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/12 21:30:51 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_SIZE 48
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363	

# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx; //mlx init
	void	*main_win; //main game window
	void	*img; //image
	void	*wall_img; //wall image
	void	*floor_img; //floor image
	void	*collectible_img; //collectible image
	void	*exit_img; //exit image
	void	*player_img; //player image
	char	**map;	//map in the 2D Array
	char	*map_file_name;
	int		win_h; //window height
	int		win_w; //window width
	int		map_height; // the height of the map
	int		map_width;  // the width of the map
	int		is_player;	// is there a player?
	int		is_exit;	// is there an exit?
	int		is_collect; // amount of collectibles
	int		counter;  // counter for moves
	int		player_x; // x position of the player
	int		player_y; // y position of the player
}	t_game;

typedef struct s_floodfill
{
	char	**map;

}	t_floodfill;

//Read amount of columns in map | map_parser.c
int		columns_in_map(char *file_name, t_game *game);

//Read amount of lines in map (rows) | map_parser.c
int		lines_in_map(char *file_name);

//function which opens a file, and print map in console | map_parser.c
void	open_and_print(char *file_name);

//function which checks name of the map file | error_handler.c
size_t	is_good_file(char *str, char *file_name);

//functions which is handlign keyboard input | keyboard_input.c
int		main_window_keys(int key, t_game *game);

//function which safely turn off the program | keyboard_input.c
int		exit_game(t_game *game);

//function which creates window | manage_window.c 
void	create_main_window(t_game *game);

//function which is handling wrong input | error_handler.c
void	error_handling(int argc, char *argv, t_game *game);

//function allocate memory for map + saves it in a 2D array | map_parser.c
void	map_to_array(char *file_name, t_game *game);

//function which prints an error and free the memory | error_handler.c
void	error_game(const char *text, t_game *game);

//function
void	print_map(t_game *game);

void	search_map(t_game *game);

int		is_correct_char(char c, t_game *game);

//Function which is drawing images in the window | render.c
void	put_images_map(t_game *game);

//Function which sets images to void pointers | main.c
void 	set_imgval(t_game *game);

//Functionw that destroys xpm images | manage_window.c
void	destroy_img(t_game *game); 

void	char_mover(t_game *game, int x, int y);
void	player_cords(t_game *game);

char	**copy_to_flood(t_game *game);

void	print_copy_map(t_game *game);


#endif