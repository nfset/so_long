/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:33:50 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/11 16:53:49 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	is_good_file(char *str, char *file_name)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(file_name);
	i = ft_strlen(str);
	while (j > 0)
	{
		if (str[i] != file_name[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

void	error_handling(int argc, char *argv, t_game *game)
{
	if (argc != 2)
	{
		ft_printf("Not enough or too many arguments");
		exit(EXIT_SUCCESS);
	}
	else if (ft_strlen(argv) < 5)
	{
		ft_printf("File name is too short");
		exit(EXIT_SUCCESS);
	}
	else if (!is_good_file(argv, ".ber"))
	{
		ft_printf("Wrong file type");
		exit(EXIT_SUCCESS);
	}
}
