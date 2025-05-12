/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:44:13 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/12 19:30:52 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//void	put_image(t_game *game, int x, int y, void *img)
//{
//	mlx_put_image_to_window(game->mlx, game->main_win,
//		img, x * IMG_SIZE, y * IMG_SIZE);
//}
void 	set_imgval(t_game *game)
{
	game->wall_img = NULL;
	game->exit_img = NULL;
	game->floor_img = NULL;
	game->collectible_img = NULL;
	game->player_img = NULL;
	game->counter = 0;

	game->wall_img = mlx_xpm_file_to_image(game->mlx,
		"textures/metal_wall.xpm", &(int){48}, &(int){48});
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
		"textures/void.xpm", &(int){48}, &(int){48});
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
		"textures/tile_floor.xpm", &(int){48}, &(int){48});
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
		"textures/collectible.xpm", &(int){48}, &(int){48});
	game->player_img = mlx_xpm_file_to_image(game->mlx,
		"textures/player.xpm", &(int){48}, &(int){48});
	if (game->collectible_img == NULL || game->exit_img == NULL
		|| game->wall_img == NULL || game->exit_img == NULL
		||	game->player_img == NULL)
		exit_game(game);
}

void	put_images_map(t_game *game)
{
	int	i;
	int	j;
	printf("Wall: %p\nFloor: %p\nPlayer: %p\nCollectible: %p\n", game->wall_img, game->floor_img, game->player_img, game->collectible_img);
	printf("\nExit: %p\n", game->exit_img);
	i = 0;
	while (i < game->map_height) //game->map_height
	{
		j = 0;
		while (j < game->map_width) //game->map_width
		{
			if (game->map[i][j] == '1')
			mlx_put_image_to_window(game->mlx, game->main_win, game->wall_img, j * 48, i * 48);
			else if (game->map[i][j] == '0')
			mlx_put_image_to_window(game->mlx, game->main_win, game->floor_img, j * 48, i * 48);
			else if (game->map[i][j] == 'C')
			mlx_put_image_to_window(game->mlx, game->main_win, game->collectible_img, j * 48, i * 48);
			else if (game->map[i][j] == 'E')
			mlx_put_image_to_window(game->mlx, game->main_win, game->exit_img, j * 48, i * 48);
			else if (game->map[i][j] == 'P')
			mlx_put_image_to_window(game->mlx, game->main_win, game->player_img, j * 48, i * 48);
			j++;
		}
		i++;
	}
}
