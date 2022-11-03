/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:34:28 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/27 18:50:28 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_asset2(char chr, int x, int y, t_game *game)
{
	mlx_image_t			*img;
	mlx_image_t			*bg;

	img = NULL;
	bg = NULL;
	if (chr && chr == '1')
		img = game->map.wall.img;
	else if (chr && chr == 'P')
	{
		game->player.x = y;
		game->player.y = x;
	}
	else if (chr && chr == 'E')
		img = game->map.exit.img;
	else if (ft_isprint(chr) && (COMPARE_CHAR2 || COMPARE_NL || COMPARE_CHAR1))
		call_error(0, game, 0);
	if (img)
		mlx_image_to_window(game->mlx, img, y * 32, x * 32);
	else if (chr != '\0' && chr != '\n')
	{
		bg = game->map.bg.img;
		mlx_image_to_window(game->mlx, bg, y * 32, x * 32);
		game->player.player_position.x = x * 32;
		game->player.player_position.y = y * 32;
	}
}

void	generate_map(t_game *game)
{
	int					x;
	int					y;
	char				chr;

	x = 0;
	y = 0;
	while (game->map.mtrx[x])
	{
		while (game->map.mtrx[x][y])
		{
			chr = game->map.mtrx[x][y];
			if (chr == '0' || chr == 'C')
				load_asset(chr, x, y, game);
			else
				load_asset2(chr, x, y, game);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(game->mlx,
		game->player.pj.img, game->player.player_position.y,
		game->player.player_position.x);
}

void	init_mlx(t_game *game)
{
	int				fd;

	fd = open("./assets/pj.png", O_RDONLY);
	if (fd == -1)
		call_error(2, game, fd);
	close(fd);
	game->mlx = mlx_init((game->map.map_width - 1) * 32,
			(game->map.map_height + 1) * 32, "so_long", true);
	game->g_img = mlx_new_image(game->mlx,
			(game->map.map_width - 1) * 32, game->map.map_height * 32);
	init_images(game);
	mlx_key_hook(game->mlx, &my_hook, game);
	generate_map(game);
	mlx_image_to_window(game->mlx, game->g_img, 0, 0);
}

int	check_move(t_game *g)
{
	if (!ft_strchr(&g->map.mtrx[g->player.x][g->player.y], '1'))
		return (0);
	else
		return (1);
}

void	free_all(t_game *game, int flag)
{
	int	i;

	if (game->map.mtrx)
	{
		i = game->map.map_height;
		while (i >= 0)
		{
			free(game->map.mtrx[i]);
			i--;
		}
		free(game->map.mtrx);
	}
	if (flag == 0)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
