/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:18:03 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/19 15:20:30 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RED_COLOR "\033[0;31m"
# define NO_COLOR "'\033[0m"
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# include "so_long.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <sys/wait.h>

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_img
{
	mlx_image_t	*img;
}t_img;

typedef struct s_map
{
	char		**mtrx;
	t_img		collective;
	t_img		exit;
	t_img		bg;
	t_img		wall;
	char		*path;
	int			map_width;
	int			map_height;
}t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			total_collectibles;
	int			actual_collectibles;
	int			status;
	mlx_image_t	*pj;
	t_point		player_position;
	int			moves;
}t_player;

typedef struct s_game
{
	t_map				map;
	t_player			player;
	mlx_image_t			*g_img;
	mlx_t				*mlx;
}t_game;

//Check
int		check_side_wall(t_game *game);
int		check_front_wall(t_game *game);
int		check_last_wall(t_game *game);
int		check_map(t_game *game);
int		check_items(t_game *game);

void	my_hook(mlx_key_data_t keydata, void *param);
void	call_error(int flag, t_game *game, int fd);
void	add_collectible(t_game *game, mlx_image_t *img);
void	get_collectible(t_game *game, int playerpos, char flag);
void	open_door(t_game *game);
void	generate_map(t_game *game);
void	load_asset(char chr, int x, int y, t_game *game);
void	load_asset2(char chr, int x, int y, t_game *game);
void	init_mlx(t_game *game);
void	free_all(t_game *game, int flag);

#endif