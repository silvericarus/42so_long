/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:42:32 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/27 16:27:17 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	col_x(int playerpos, t_game *game, int i, t_point p)
{
	if (p.x == playerpos && p.y == game->player.y
		&& game->map.collective.img->instances[i].enabled == true)
	{
		game->map.collective.img->instances[i].enabled = false;
		game->player.actual_collectibles++;
		game->map.mtrx[game->player.y][playerpos] = '0';
	}
}

void	col_y(int playerpos, t_game *game, int i, t_point p)
{
	if (p.y == playerpos && p.x == game->player.x
		&& game->map.collective.img->instances[i].enabled == true)
	{
		game->map.collective.img->instances[i].enabled = false;
		game->player.actual_collectibles++;
		game->map.mtrx[playerpos][game->player.x] = '0';
	}
}

void	open_door(t_game *game)
{
	if (game->player.actual_collectibles == game->player.total_collectibles)
	{
		ft_printf("\033[0;32m You Win!\033[0m\n");
		free_all(game, 1);
	}
	else
		call_error(5, game, 0);
}

void	call_error(int flag, t_game *game, int fd)
{
	if (flag == 0)
		ft_printf("\033[0;31m Error: There's a Design Error In The Map.\033[0m\n");
	if (flag == 1)
		ft_printf("\033[0;31m Error: You Must Include a .ber File.\033[0m\n");
	if (flag == 2)
	{
		close(fd);
		ft_printf("\033[0;31m Error: File Can't Be Opened Right.\033[0m\n");
	}
	if (flag == 3)
		ft_printf("\033[0;31m Error: Map Error.\033[0m\n");
	if (flag == 4)
		ft_printf("\033[0;31m Error: World Can't Be Plain.\033[0m\n");
	if (flag == 5)
		ft_printf("\033[0;31m Error: Take All The Collectibles.\033[0m\n");
	if (flag == 0)
		free_all(game, 0);
	if (flag != 5 && flag != 0)
		exit(EXIT_FAILURE);
}

void	get_collectible(t_game *game, int playerpos, char flag)
{
	int			colnum;
	int			i;
	t_point		p;

	colnum = game->player.total_collectibles;
	i = 0;
	while (i < colnum)
	{
		p.x = game->map.collective.img->instances[i].x / 32;
		p.y = game->map.collective.img->instances[i].y / 32;
		if (flag == 'x')
		{
			col_x(playerpos, game, i, p);
			i++;
		}
		else
		{
			col_y(playerpos, game, i, p);
			i++;
		}
	}
}
