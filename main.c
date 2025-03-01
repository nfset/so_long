/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:14:53 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/27 15:12:17 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->main_win = mlx_new_window(game->mlx, 700, 200, "so_long");
	mlx_hook(game->main_win, 17, 0, exit_game, game);
	mlx_key_hook(game->main_win, main_window_keys, game);
	mlx_loop(game->mlx);
	return (0);
}
