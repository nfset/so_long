/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:59:05 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/15 16:35:25 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\nHeight: %d\nWidth :%d\n", game->map_height, game->map_width);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[0][j] != '1'
				|| game->map[i][game->map_width - 1] != '1'
				|| game->map[i][0] != '1'
				|| game->map[game->map_height - 1][j] != '1')
				error_game("Map is not surrouned by wall", game);
			j++;
		}
		i++;
	}
}
