/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:08 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/06 20:49:15 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **map_to_array(char *file_name, t_game *game)
{
	char **pierdolona_w_dupe;

	game->map_height = lines_in_map(file_name);
	game->map_width = columns_in_map(file_name);

	pierdolona_w_dupe = (char **)ft_calloc(game->map_height + 1, sizeof(char));
}


int	columns_in_map(char *file_name)
{
	int		fd;
	int		columns;
	char	*line;
	char	*huj;

	fd = open(file_name, O_RDONLY);
	huj = get_next_line(fd);
	if (!huj)
		exit(EXIT_FAILURE);
	line = ft_strtrim(huj, "\n");
	columns = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		free(huj);
		huj = get_next_line(fd);
		line = ft_strtrim(huj, "\n");
		if (line != NULL && columns != ft_strlen(line) )
		{
			ft_printf("wrong shape of the map\n");
			exit(EXIT_FAILURE);
		}
	}
	close(fd);
	return (columns);
}

int	lines_in_map(char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(fd);
	ft_printf("\n");
	close(fd);
	return (i);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}
