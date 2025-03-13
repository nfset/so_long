/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:44:39 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/13 18:28:13 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	search_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				game->is_player = 1;
			else if (game->map[i][j] == 'E')
				game->is_exit = 1;
			else if (game->map[i][j] == 'C')
				game->is_collect = 1;
			j++;
		}
		i++;
	}
	if (game->is_player == 1 && game->is_exit == 1 && game->is_collect)
	{
		ft_printf("Map is valid\n");
		return (1);
	}
	else
	{
		ft_printf("Map is invalid\n");
		return (0);
	}
}
