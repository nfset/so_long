/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:14:53 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/06 20:41:00 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	error_handling(argc, argv[1], game);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free(game);
		return (EXIT_FAILURE);
	}
	int rows = lines_in_map(argv[1]);
	int columns = columns_in_map(argv[1]);
	ft_printf("\n rows: %d \n columns: %d \n", rows, columns);
	create_main_window(game);
	mlx_hook(game->main_win, 17, 0, exit_game, game);
	mlx_key_hook(game->main_win, main_window_keys, game);
	mlx_loop(game->mlx);
	return (0);
}
