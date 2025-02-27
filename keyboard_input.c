/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:06:13 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/27 15:13:01 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_window_keys(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	else if (key == XK_Up)
		exit_game(game);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->main_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
	return (0);
}