/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:44:39 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/12 21:47:32 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_correct_char(char c, t_game *game)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	error_game("Map contains invalid characters", game);
	return (0);
}

void	search_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width && is_correct_char(game->map[i][j], game))
		{
			if (game->map[i][j] == 'P')
				game->is_player += 1;
			else if (game->map[i][j] == 'E')
				game->is_exit += 1;
			else if (game->map[i][j] == 'C')
				game->is_collect += 1;
			j++;
		}
		i++;
	}
	if (game->is_player == 1 && game->is_exit == 1 && game->is_collect != 0)
	{
		ft_printf("Map is valid\n");
		print_copy_map(game);
	}
	else
		error_game("Map is invalid", game);
}
