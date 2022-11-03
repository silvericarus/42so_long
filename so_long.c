/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:06:44 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/27 19:04:49 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_height(t_game *game, char **argv)
{
	char	*line;
	int		fd;

	game->map.map_width = 0;
	game->map.path = argv[1];
	fd = open(game->map.path, O_RDONLY);
	if (fd < 0)
		call_error(2, game, 0);
	game->map.map_height = 0;
	line = get_next_line(fd);
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) > game->map.map_width)
			game->map.map_width = ft_strlen(line);
		game->map.map_height++;
	}
	if (game->map.map_height == 0)
		call_error(3, game, 0);
	else if (game->map.map_height == 1)
		call_error(4, game, 0);
	close(fd);
}

void	create_map(t_game *g)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(g->map.path, O_RDONLY);
	g->map.mtrx[i] = get_next_line(fd);
	while (g->map.mtrx[i] != NULL)
	{
		if (!ft_strncmp(g->map.mtrx[i], "", ft_strlen(g->map.mtrx[i])))
			g->map.mtrx[i] = get_next_line(fd);
		i++;
		g->map.mtrx[i] = get_next_line(fd);
	}
	close(fd);
}

void	load_asset(char chr, int x, int y, t_game *game)
{
	mlx_image_t			*img;
	mlx_image_t			*bg;

	img = NULL;
	bg = NULL;
	if (chr && chr == '0')
		bg = game->map.bg.img;
	else if (chr && chr == 'C')
	{
		img = game->map.collective.img;
		bg = game->map.bg.img;
		game->player.total_collectibles++;
	}
	if (img && bg)
	{
		mlx_image_to_window(game->mlx, bg, y * 32, x * 32);
		mlx_image_to_window(game->mlx, img, y * 32, x * 32);
	}
	else if (img)
		mlx_image_to_window(game->mlx, img, y * 32, x * 32);
	else if (chr != '\0' && chr != '\n')
	{
		bg = game->map.bg.img;
		mlx_image_to_window(game->mlx, bg, y * 32, x * 32);
	}
}

void	init_game(t_game *game)
{
	game->map.mtrx = malloc(game->map.map_height * game->map.map_width);
	ft_bzero(game->map.mtrx, game->map.map_height * game->map.map_width);
	game->player.x = 0;
	game->player.y = 0;
	game->player.total_collectibles = 0;
	game->player.actual_collectibles = 0;
	game->player.status = 1;
	game->player.moves = 0;
}

// void ft_void()
// {
// 	system("leaks -q so_long");
// }

int	main(int args, char **argv)
{
	t_game				game;

	if (args == 2)
	{
		map_height(&game, argv);
		init_game(&game);
		create_map(&game);
		if (check_map(&game))
		{
			init_mlx(&game);
			if (!game.mlx)
				free_all(&game, 0);
			mlx_loop(game.mlx);
			mlx_terminate(game.mlx);
			free_all(&game, 1);
		}
		else
			call_error(0, &game, 0);
	}
	else
		call_error(1, &game, 0);
}
