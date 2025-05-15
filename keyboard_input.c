/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:06:13 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/15 16:33:38 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_window_keys(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	else if (key == XK_Up)
		char_mover(game, 0, -1);
	else if (key == XK_Down)
		char_mover(game, 0, 1);
	else if (key == XK_Left)
		char_mover(game, -1, 0);
	else if (key == XK_Right)
		char_mover(game, 1, 0);
	else
		return (0);
	return (0);
}
