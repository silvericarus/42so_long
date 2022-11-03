/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:03:03 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/27 18:08:02 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_left(t_game *game)
{
	if (game->map.mtrx[game->player.y][game->player.x - 1] == 'C')
		get_collectible(game, game->player.x - 1, 'x');
	else if (game->map.mtrx[game->player.y][game->player.x - 1] == 'E')
		open_door(game);
	else
	{
		game->player.pj.img->instances[0].x -= 32;
		game->player.x--;
		ft_printf("Movements: %d\n", ++game->player.moves);
	}
}

void	movement_right(t_game *game)
{
	if (game->map.mtrx[game->player.y][game->player.x + 1] == 'C')
		get_collectible(game, game->player.x + 1, 'x');
	else if (game->map.mtrx[game->player.y][game->player.x + 1] == 'E')
		open_door(game);
	else
	{
		game->player.pj.img->instances[0].x += 32;
		game->player.x++;
		ft_printf("Movements: %d\n", ++game->player.moves);
	}
}

void	movement_up(t_game *game)
{
	if (game->map.mtrx[game->player.y - 1][game->player.x] == 'C')
		get_collectible(game, game->player.y - 1, 'y');
	else if (game->map.mtrx[game->player.y - 1][game->player.x] == 'E')
		open_door(game);
	else
	{
		game->player.pj.img->instances[0].y -= 32;
		game->player.y--;
		ft_printf("Movements: %d\n", ++game->player.moves);
	}
}

void	movement_down(t_game *game)
{
	if (game->map.mtrx[game->player.y + 1][game->player.x] == 'C')
		get_collectible(game, game->player.y + 1, 'y');
	else if (game->map.mtrx[game->player.y + 1][game->player.x] == 'E')
		open_door(game);
	else
	{
		game->player.pj.img->instances[0].y += 32;
		game->player.y++;
		ft_printf("Movements: %d\n", ++game->player.moves);
	}
}

void	my_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		if (game->map.mtrx[game->player.y - 1][game->player.x] != '1')
			movement_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (game->map.mtrx[game->player.y + 1][game->player.x] != '1')
			movement_down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (game->map.mtrx[game->player.y][game->player.x + 1] != '1')
			movement_right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (game->map.mtrx[game->player.y][game->player.x - 1] != '1')
			movement_left(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_all(game, 1);
}
