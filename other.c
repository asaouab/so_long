/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:46:53 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 15:33:58 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	erour_norm(int count_c, int count_e, int count_p)
{
	if (count_c == 0)
		error ("Error\nplayer can't collecte");
	if (count_e != 1 || count_p != 1)
		error ("Error\nThere should be 1 E & 1 P on the map");
}

void	check_map_elements(t_map *T)
{
	int	x;
	int	y;
	int	count_c;
	int	count_e;
	int	count_p;

	x = 0;
	count_c = 0;
	count_e = 0;
	count_p = 0;
	while (T->map[x])
	{
		y = 0;
		while (T->map[x][++y])
		{
			if (T->map[x][y] == 'C')
				count_c++;
			if (T->map[x][y] == 'P')
				count_p++;
			if (T->map[x][y++] == 'E')
			count_e++;
		}
		x++;
	}
	erour_norm(count_c, count_e, count_p);
}

void	check_map_components(t_map *T)
{
	int	e_count;
	int	p_count;
	int	c_count;

	e_count = 0;
	p_count = 0;
	c_count = 0;
	check_map_helper(T, e_count, p_count, c_count);
}

int	frame(void)
{
	error("we are done");
	return (0);
}

void	hook_helper(t_map *T)
{
	draw_map(T);
	ft_p_position(T);
	mlx_hook(T->win, 02, 0, move, T);
	mlx_hook(T->win, 13, 0, move, T);
	mlx_hook(T->win, 17, 0, frame, NULL);
	mlx_loop(T->ret);
}
