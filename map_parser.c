/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:08 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/04 16:04:56 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_and_print(char *file_name)
{		
		int		fd;
		char	*line;

		fd = open(file_name, 0, O_RDONLY);
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		
		printf("\n");
}
char	**map_to_array(char *file_name)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(file_name, 0, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = line;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (map);
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}
