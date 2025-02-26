/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:14:53 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/26 18:17:33 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_game
{
    void *mlx;
	void *main_win;
    void *key;
	char **map;
    int window_height;
    int window_width;

}  t_game;

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->main_win);
	free(game);
	exit(EXIT_SUCCESS);
}

int		main_window_keys(int key, t_game *game)
{
	if (key == 0xFF1B)
		exit_game(game);
	else if (key == 0xFF52)
		exit_game(game);
	return (0);
}

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game);
		return (1);
	}
	game->main_win = mlx_new_window(game->mlx, 800, 700, "Main Window");
	mlx_key_hook(game->main_win, main_window_keys, game);
	mlx_loop(game->mlx);

	return (0);
}
