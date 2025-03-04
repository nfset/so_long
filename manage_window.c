/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:20:00 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/01 14:58:34 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->main_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
void	create_main_window(t_game *game)
{
    game->win_h = 800;
    game->win_w = 600;
    game->main_win = mlx_new_window(game->mlx, game->win_w,
        game->win_h, "so_long");
    if (!game->main_win)
        exit_game(game);
}