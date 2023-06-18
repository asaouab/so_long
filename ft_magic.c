/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:14:27 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 15:15:22 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	mlx_graphic(t_map *T)
{
	int	w;
	int	h;

	T->ret = mlx_init();
	if (!T->ret)
		exit(1);
	T->win = mlx_new_window(T->ret, (ft_strlen(T->map[0]) - 1) * 50,
			T->len * 50, "you are in the game");
	if (!T->win)
		exit(1);
	T->floor = mlx_xpm_file_to_image(T->ret, "img/floor.xpm", &w, &h);
		T->babe = mlx_xpm_file_to_image(T->ret, "img/babe.xpm", &w, &h);
	if (!T->babe)
		exit(1);
	T->walls = mlx_xpm_file_to_image(T->ret, "img/wal2-_2_.xpm", &w, &h);
	if (!T->walls)
		exit(1);
	T->joha = mlx_xpm_file_to_image(T->ret, "img/joha.xpm", &w, &h);
	if (!T->joha)
		exit(1);
	T->money = mlx_xpm_file_to_image(T->ret, "img/money.xpm", &w, &h);
	if (!T->money)
		exit(1);
	hook_helper(T);
}

void	check_map_helper(t_map *T, int e_count, int p_count, int c_count)
{
	int	i;
	int	j;

	i = -1;
	while (T->map[++i])
	{
		j = -1;
		while (T->map[i][++j])
		{
			if (T->map[i][j] == 'E' || T->map[i][j] == 'C'
				|| T->map[i][j] == 'P' || T->map[i][j] == '0'
				|| T->map[i][j] == '1' || T->map[i][j] == '\n')
			{
				if (T->map[i][j] == 'E')
					e_count++;
				else if (T->map[i][j] == 'P')
					p_count++;
				else if (T->map[i][j] == 'C')
					c_count++;
			}
			else
				error("Error\nplease use a real stuff in your map");
		}
	}
T->items_c = c_count;
}
