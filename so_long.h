/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:34:25 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/27 16:43:48 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>

typedef struct s_game
{
	void	*mlx; //mlx init
	void	*main_win; //main game window
	char	**map;
	int		win_h; //window height
	int		win_w; //window width
}	t_game;

//functions which is handlign keyboard input | keyboard_input.c
int	main_window_keys(int key, t_game *game);

//function which safely turn off the program | keyboard_input.c
int	exit_game(t_game *game);

#endif