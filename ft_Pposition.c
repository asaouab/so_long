/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Pposition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:30:39 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 18:48:14 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player_left(int key, t_map *T)
{
	if ((key == 123 || key == 0) && T->map[T->setar][T->indix - 1] != '1')
	{
		if (T->map[T->setar][T->indix - 1] == 'E' && T->items_c == 0)
		{
			write(1, "we are done\n", 13);
			exit(0);
		}
		else if (T->map[T->setar][T->indix - 1] == 'E' && T->items_c != 0)
			return ;
		if (T->map[T->setar][T->indix - 1] == 'C')
			T->items_c--;
			T->map[T->setar][T->indix] = '0';
			T->map[T->setar][T->indix - 1] = 'P';
			T->indix -= 1;
			T->count++;
		printf("%d\n", T->count);
	}
}

void	ft_move_player_right(int key, t_map *T)
{
	if ((key == 124 || key == 2) && T->map[T->setar][T->indix + 1] != '1')
	{
		if (T->map[T->setar][T->indix + 1] == 'E' && T->items_c == 0)
		{
			write(1, "we are done\n", 13);
			exit(0);
		}
		else if (T->map[T->setar][T->indix + 1] == 'E' && T->items_c != 0)
			return ;
		if (T->map[T->setar][T->indix + 1] == 'C')
				T->items_c--;
			T->map[T->setar][T->indix] = '0';
			T->map[T->setar][T->indix + 1] = 'P';
			T->indix += 1;
			T->count++;
		printf("%d\n", T->count);
	}
}

void	ft_move_player_up(int key, t_map *T)
{
	if ((key == 126 || key == 13) && T->map[T->setar - 1][T->indix] != '1')
	{
		if (T->map[T->setar - 1][T->indix] == 'E' && T->items_c == 0)
		{
			write(1, "we are done\n", 13);
			exit(0);
		}
		else if (T->map[T->setar - 1][T->indix] == 'E' && T->items_c != 0)
			return ;
		if (T->map[T->setar - 1][T->indix] == 'C')
				T->items_c--;
			T->map[T->setar][T->indix] = '0';
			T->map[T->setar - 1][T->indix] = 'P';
			T->setar -= 1;
			T->count++;
		printf("%d\n", T->count);
	}
}

void	ft_move_player_down(int key, t_map *T)
{
	if ((key == 125 || key == 1) && T->map[T->setar + 1][T->indix] != '1')
	{
		if (T->map[T->setar + 1][T->indix] == 'E' && T->items_c == 0)
		{
			write(1, "we are done\n", 13);
			exit(0);
		}
		else if (T->map[T->setar + 1][T->indix] == 'E' && T->items_c != 0)
			return ;
		if (T->map[T->setar + 1][T->indix] == 'C')
				T->items_c--;
			T->map[T->setar][T->indix] = '0';
			T->map[T->setar + 1][T->indix] = 'P';
			T->setar += 1;
			T->count++;
		printf("%d\n", T->count);
	}
}

int	move(int key, t_map *T)
{
	if (key == 123 || key == 0 || key == 124 || key == 2
		|| key == 125 || key == 1 || key == 126 || key == 13)
	{
		ft_move_player_left(key, T);
		ft_move_player_right(key, T);
		ft_move_player_up(key, T);
		ft_move_player_down(key, T);
		mlx_clear_window(T->ret, T->win);
		draw_map(T);
	}
	else if (key == 53)
	{
		write(1, "we are done\n", 13);
		exit(0);
	}
	return (0);
}
