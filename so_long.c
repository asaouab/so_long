/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:28:11 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 18:49:40 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_norm(t_map *T, int x, int y)
{
	if (T->map[x][y] == 'P')
	{
		mlx_put_image_to_window(T->ret, T->win, T->floor, y * 50, x * 50);
		mlx_put_image_to_window(T->ret, T->win, T->joha, y * 50, x * 50);
	}
	if (T->map[x][y] == 'C')
	{
		mlx_put_image_to_window(T->ret, T->win, T->floor, y * 50, x * 50);
		mlx_put_image_to_window(T->ret, T->win, T->money, y * 50, x * 50);
	}
	if (T->map[x][y] == 'E')
		mlx_put_image_to_window(T->ret, T->win, T->babe, y * 50, x * 50);
}

void	draw_map(t_map *T)
{
	int	x;
	int	y;

	x = 0;
	while (T->copy_map[x])
	{
	y = 0;
		while (T->map[x][y])
		{
			if (T->map[x][y] == '1')
				mlx_put_image_to_window(T->ret, T->win,
					T->walls, y * 50, x * 50);
			if (T->map[x][y] == '0')
				mlx_put_image_to_window(T->ret, T->win,
					T->floor, y * 50, x * 50);
			handle_norm(T, x, y);
			y++;
		}
		x++;
	}
}

void	ft_p_position(t_map *T)
{
	int	x;
	int	y;

	x = 0;
	while (T->map[x])
	{
		y = 0;
		while (T->map[x][y])
		{
			if (T->map[x][y] == 'P')
			{
				T->setar = x;
				T->indix = y;
				break ;
			}
		y++;
		}
	x++;
	}
}

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write (1, &s[i++], 1);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_map	*t;

	t = malloc(sizeof(t_map));
	check_arg(argc, argv);
	ft_lines_number(argv, t);
	ft_fillmap(argv, t);
	check_column_length(t);
	check_map_components(t);
	check_column_length(t);
	make_map_copy(t);
	check_p_mapcopy(t);
	check_rest_c_inmapcopy(t);
	check_exit_sides(t);
	check_map_elements(t);
	mlx_graphic(t);
	return (0);
}
