/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:02:57 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 18:06:09 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	make_map_copy(t_map *T)
{
	int	x;
	int	y;
	int	len ;

	T->copy_map = malloc(sizeof(char *) * (T->len + 1));
		x = 0;
	while (T->map[x])
	{
		len = ft_strlen(T->map[x]);
		T->copy_map[x] = malloc(sizeof(char) * (len + 1));
		y = 0;
		while (T->map[x][y])
		{
			T->copy_map[x][y] = T->map[x][y];
			y++;
		}
		T->copy_map[x][y] = '\0';
		x++;
	}
	T->copy_map[x] = NULL;
}

int	ft_position(t_map *T, int x, int y)
{
	int	result;

	result = 0;
	if (T->copy_map[x][y - 1] == '0' || T->copy_map[x][y - 1] == 'C')
	{
		result = 7;
		T->copy_map[x][y - 1] = 'P';
	}
	if (T->copy_map[x][y + 1] == '0' || T->copy_map[x][y + 1] == 'C')
	{
		result = 7;
		T->copy_map[x][y + 1] = 'P';
	}
	if (T->copy_map[x - 1][y] == '0' || T->copy_map[x - 1][y] == 'C')
	{
		result = 7;
		T->copy_map[x - 1][y] = 'P';
	}
	if (T->copy_map[x + 1][y] == '0' || T->copy_map[x + 1][y] == 'C')
	{
		result = 7;
		T->copy_map[x + 1][y] = 'P';
	}
	return (result);
}

void	check_p_mapcopy(t_map *T)
{
	int	x;
	int	y;

	x = 0;
	while (T->copy_map[x])
	{
		y = 0;
		while (T->copy_map[x][y])
		{
			if (T->copy_map[x][y] == 'P' && ft_position(T, x, y) == 7)
			{
				y = 0;
				x = 0;
			}
			y++;
		}
		x++;
	}
}

void	check_exit_sides(t_map *T)
{
	int	x;
	int	y;

	x = 0;
	while (T->copy_map[x])
	{
		y = 0;
		while (T->copy_map[x][y])
		{
			if (T->copy_map[x][y] == 'E')
			{
				if (T->copy_map[x - 1][y] == 'P' || T->copy_map[x + 1][y] == 'P'
					|| T->copy_map[x][y - 1] == 'P'
					|| T->copy_map[x][y + 1] == 'P')
					y++;
				else
					error("Error\nsomething wrong in your copy_map (E)");
			}
			y++;
		}
		x++;
	}
}

void	check_rest_c_inmapcopy(t_map *T)
{
	int	x;
	int	count_c;
	int	y;

	x = 0;
	count_c = 0;
	while (T->copy_map[x])
	{
		y = 0;
		while (T->copy_map[x][y])
		{
			if (T->copy_map[x][y] == 'C')
				count_c++;
			y++;
		}
		x++;
	}
	if (count_c != 0)
	{
		error("Error\nsomething wrong in your copy_map (C)");
	}
}
