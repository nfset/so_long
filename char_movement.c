/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:18:23 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/12 20:51:50 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_cords(t_game *game)
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
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	char_mover(t_game *game, int hor, int vert) //vert - vertical | hor - horizontal
{
	int	new_vert;
	int	new_hor;

	printf("old_x: %d\nold_y %d\n", game->player_x, game->player_y);
	new_vert = game->player_y + vert;
	new_hor = game->player_x + hor;
	printf("new_x: %d\nnew_y %d\n collectibles: %d \n", new_hor, new_vert, game->is_collect);
	if (game->map[new_vert][new_hor] == '1')
		return ;
	if (game->is_collect != 0 && game->map[new_vert][new_hor] == 'E')
		return ;	
	if (game->map[new_vert][new_hor] == 'C')
		game->is_collect--;
	if (game->is_collect == 0 && game->map[new_vert][new_hor] == 'E')
		error_game("You have won!", game);
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_vert][new_hor] = 'P';
	game->player_x = new_hor;
	game->player_y = new_vert;
	game->counter = game->counter + 1;
	mlx_put_image_to_window(game->mlx, game->main_win,
		game->player_img, game->player_x * 48, game->player_y * 48);
	ft_printf("\n\rThat's your: %d move\n", game->counter);
	put_images_map(game);
}

