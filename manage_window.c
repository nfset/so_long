/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:20:00 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/15 16:34:33 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_map_flood(t_game *game, t_floodfill *flood)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(flood->map[i]);
		i++;
	}
	free(flood->map);
	free(flood);
}

void	destroy_img(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
}

int	exit_game(t_game *game)
{
	if (game->main_win != NULL)
		mlx_destroy_window(game->mlx, game->main_win);
	if (game->map != NULL)
		free_map(game);
	if (game->wall_img || game->exit_img || game->floor_img
		|| game->collectible_img || game->player_img)
		destroy_img(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}

void	create_main_window(t_game *game)
{
	game->win_h = game->map_height * 48;
	game->win_w = game->map_width * 48;
	game->main_win = mlx_new_window(game->mlx, game->win_w,
			game->win_h, "so_long");
	if (!game->main_win)
		exit_game(game);
}
