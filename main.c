/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:14:53 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/25 15:18:05 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

typedef struct s_game
{
    void *main_mlx;
	void *main_window;
    void *key;
    int window_height;
    int window_width;

}  t_game;

// int		main_window_keys(void *key, void *mlx, void *main_window);
// {
// 	key = t_game->key;
// 	if (key == 0xFF1B)
// 		mlx_destroy_window(mlx, main_window);
// }

void	*create_main_window(void *mlx)
{
	void	*window;

	window = mlx_new_window(mlx, 800, 700, "Main Window");
	return (window);

}

int	main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->main_mlx = mlx_init();
	if (!game->main_mlx)
	{
		free(game);
		return (1);
	}
	game->main_window = create_main_window(game->main_mlx);
	mlx_loop(game->main_mlx);

	free(game);
	return (0);
}
