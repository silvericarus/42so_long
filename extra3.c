/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:51:14 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/27 18:49:02 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	plus_when_player(t_game *game, int p, int index)
{
	if (ft_strchr(game->map.mtrx[index], 'P'))
		p++;
	return (p);
}

void	init_images(t_game *game)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png("./assets/pj.png");
	game->player.pj.img = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./assets/gem.png");
	game->map.collective.img = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./assets/stairs.png");
	game->map.exit.img = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./assets/bg.png");
	game->map.bg.img = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./assets/wall.png");
	game->map.wall.img = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
}
