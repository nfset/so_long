/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:34:25 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/13 18:47:27 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx; //mlx init
	void	*main_win; //main game window
	char	**map;
	char	*map_file_name;
	int		win_h; //window height
	int		win_w; //window width
	int		map_height;
	int		map_width;
	int		is_player;
	int		is_exit;
	int		is_collect;

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

void	print_map(t_game *game);

int		search_map(t_game *game);

#endif