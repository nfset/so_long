/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:43:27 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/15 16:33:16 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_to_flood(t_game *game)
{
	char	**map_copy;
	int		i;
	int		j;

	i = 0;
	map_copy = ft_calloc(game->map_height, sizeof(char *));
	if (!map_copy)
		return (NULL);
	while (i < game->map_height)
	{
		map_copy[i] = ft_calloc(game->map_width, sizeof(char));
		j = 0;
		while (j < game->map_width)
		{
			map_copy[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
	return (map_copy);
}

void	flood_fill(int x, int y, t_game *game, t_floodfill *flood)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return ;
	if (flood->map[y][x] == '1' || flood->map[y][x] == 'X')
		return ;
	flood->map[y][x] = 'X';
	flood_fill(x + 1, y, game, flood);
	flood_fill(x - 1, y, game, flood);
	flood_fill(x, y + 1, game, flood);
	flood_fill(x, y - 1, game, flood);
}

void	validate_map(t_game *game, t_floodfill *flood)
{
	int	i;
	int	j;

	flood_fill(game->player_x, game->player_y, game, flood);
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C' && flood->map[i][j] != 'X')
			{
				free_map_flood(game, flood);
				error_game("cannot reach collectibles", game);
			}
			if (game->map[i][j] == 'E' && flood->map[i][j] != 'X')
			{
				free_map_flood(game, flood);
				error_game("Cannot reach exit", game);
			}
			j++;
		}
		i++;
	}
	free_map_flood(game, flood);
}

void	check_copy_map(t_game *game)
{
	t_floodfill	*flood;

	flood = ft_calloc(2, sizeof(t_floodfill));
	flood->map = copy_to_flood(game);
	player_cords(game);
	validate_map(game, flood);
}
