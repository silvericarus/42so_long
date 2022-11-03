/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgonza <albgonza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:32:02 by albgonza          #+#    #+#             */
/*   Updated: 2022/10/25 15:50:06 by albgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_items(t_game *game)
{
	int	c;
	int	p;
	int	e;
	int	i;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (game->map.mtrx[i] != NULL)
	{
		p = plus_when_player(game, p, i);
		if (ft_strchr(game->map.mtrx[i], 'P')
			!= ft_strrchr(game->map.mtrx[i], 'P'))
			p = 0;
		if (ft_strchr(game->map.mtrx[i], 'E'))
			e = 1;
		if (ft_strchr(game->map.mtrx[i], 'C'))
			c = 1;
		i++;
	}
	if (!e || !c || !p || p > 1)
		return (0);
	else
		return (1);
}

int	check_map(t_game *game)
{
	size_t	i;
	size_t	prev_width;

	i = 1;
	prev_width = 0;
	while (game->map.mtrx[i] != NULL && i < (ft_strlen(game->map.mtrx[i]) - 1))
	{
		prev_width = ft_strlen(game->map.mtrx[i - 1]);
		if (prev_width == ft_strlen(game->map.mtrx[i]))
			i++;
		else
			return (0);
	}
	if (check_front_wall(game) && check_last_wall(game)
		&& check_items(game) && check_side_wall(game))
		return (1);
	else
		return (0);
}

int	check_last_wall(t_game *game)
{
	int	i;
	int	j;

	i = game->map.map_height;
	j = 0;
	while (j < game->map.map_width - 1)
	{
		if (game->map.mtrx[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_front_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.map_width - 1)
	{
		if (game->map.mtrx[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_side_wall(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = game->map.map_width - 2;
	while (i < game->map.map_height)
	{
		if (game->map.mtrx[i][0] != '1'
			|| game->map.mtrx[i][j] != '1')
			return (0);
		else
			i++;
	}
	return (1);
}
