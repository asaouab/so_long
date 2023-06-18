/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:28:43 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 15:33:33 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef  SO_LONG_H
# define  SO_LONG_H
# include "next_line42/get_next_line.h"
# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>
# include<mlx.h>

typedef struct so_long
{
	char	**map;
	char	**copy_map;
	char	*line;
	void	*win;
	void	*babe;
	void	*joha;
	void	*walls;
	void	*money;
	void	*floor;
	void	*ret;
	int		items_c;
	int		setar;
	int		indix;
	int		len;
	int		i;
	int		count;
	int		count_ze;
	int		count_e;
}	t_map;

void		check_arg(int argc, char **argv);
void		ft_lines_number(char **argv, t_map *T);
void		ft_fillmap(char **argv, t_map *T);
void		check_column_length(t_map *T);
void		check_f_l_line(t_map *T);
void		check_map_components(t_map *T);
void		make_map_copy(t_map *T);
void		check_p_mapcopy(t_map *T);
void		check_map_elements(t_map *T);
void		check_exit_sides(t_map *T);
void		check_rest_c_inmapcopy(t_map *T);
void		ft_p_position(t_map *T);
void		draw_map(t_map *T);
int			move(int key, t_map *T);
void		error(char *s);
void		hook_helper(t_map *T);
void		mlx_graphic(t_map *T);
void		check_map_helper(t_map *T, int e_count, int p_count, int c_count);
size_t		ft_strlen(char *str);
#endif
