/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:08 by apieniak          #+#    #+#             */
/*   Updated: 2025/05/15 16:35:04 by apieniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_to_array(char *file_name, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_game("File is empty or doesn't exist", game);
	game->map_height = lines_in_map(file_name, game);
	game->map_width = columns_in_map(file_name, game);
	game->map = ft_calloc(game->map_height * game->map_width, sizeof(char *));
	if (!game->map)
		exit(1);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map_walls(game);
	close(fd);
	search_map(game);
}

int	check_shape_map(t_game *game)
{
	if (game->check_f != game->check_s && game->valid == 0)
	{
		ft_printf("ERROR! Extra character on the map");
		game->valid = 1;
		return (1);
	}
	return (0);
}

int	columns_in_map(char *file_name, t_game *game)
{
	int		fd;
	int		columns;
	char	*line;
	char	*huj;

	fd = open(file_name, O_RDONLY);
	huj = get_next_line(fd);
	if (!huj)
		error_game("File is empty or doesn't exist", game);
	line = ft_strtrim(huj, "\n");
	columns = ft_strlen(line);
	game->check_f = ft_strlen(line);
	while (line != NULL)
	{
		game->check_s = ft_strlen(line);
		check_shape_map(game);
		free(line);
		free(huj);
		huj = get_next_line(fd);
		line = ft_strtrim(huj, "\n");
	}
	close(fd);
	if (game->valid != 0)
		error_game("map not validated", game);
	return (columns);
}

int	lines_in_map(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_game("File is empty or doesn't exist", game);
	line = get_next_line(fd);
	if (!line)
		error_game("File is empty or doesn't exist", game);
	while (line != NULL)
	{
		i++;
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("\n");
	close(fd);
	return (i);
}
