/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieniak <apieniak@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:18:08 by apieniak          #+#    #+#             */
/*   Updated: 2025/03/27 14:31:23 by apieniak         ###   ########.fr       */
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
	game->map_height = lines_in_map(file_name);
	game->map_width = columns_in_map(file_name, game);
	game->map = ft_calloc(game->map_height * game->map_width, sizeof(char));
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
	close(fd);
	search_map(game);
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
		exit(EXIT_FAILURE);
	line = ft_strtrim(huj, "\n");
	columns = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		free(huj);
		huj = get_next_line(fd);
		line = ft_strtrim(huj, "\n");
		if (line != NULL && columns != ft_strlen(line))
		{	
			free(huj);
			free(line);
			ft_printf("wrong shape of the map\n");
			exit_game(game);
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
	if (fd == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
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

// void	print_map(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map_height)
// 	{
// 		ft_printf("%s", game->map[i]);
// 		i++;
// 	}
// 	ft_printf("\n");
// }
