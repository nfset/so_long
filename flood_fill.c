/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:43:27 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/12 21:49:09 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_to_flood(t_game *game)
{
	char 	**map_copy;
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
void	print_copy_map(t_game *game)
{
	int	i;
	int	j;
	char **map = copy_to_flood(game);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			ft_printf("%c", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n ABOVE ME IS COPIED MAP FLOOD FILL \n");
}
