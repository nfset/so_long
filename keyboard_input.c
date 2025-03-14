/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:06:13 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/01 14:20:34 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_window_keys(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game(game);
	else if (key == XK_Up)
		exit_game(game);
	return (0);
}
