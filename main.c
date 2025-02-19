/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:14:53 by apieniak          #+#    #+#             */
/*   Updated: 2025/02/19 18:35:55 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"

// int		main_window_keys(int key, void *p, void *mlx, void *main_window);
// {
// 	if (key == 0xFF1B)
// 		mlx_destroy_window(mlx, main_window);
// }

void	*create_main_window(void *mlx)
{
	void	*window;

	window = mlx_new_window(mlx, 800, 700, "Main Window");
	return (window);

}

int	main(void)
{
	void	*mlx_initialize;
	void	*main_window;

	mlx_initialize = mlx_init();
	main_window = create_main_window(mlx_initialize);
	mlx_loop(mlx_initialize);
	//mlx_key_hook(main_window_keys, main_window, 0);

	return (0);
}
