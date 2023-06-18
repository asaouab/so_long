/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:34:37 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/18 18:48:39 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arg(int argc, char **argv)
{
	int	fd;
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\nNumber of args is invalid", 32);
		exit(0);
	}
	while (argv[1][i] != '\0')
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e'
		|| argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
	{
		write(1, "Error\ncheck map extention", 26);
	}
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "file does not exit/n", 21);
		exit(0);
	}
	close(fd);
}

void	ft_lines_number(char **argv, t_map *T)
{
	int	fd;

	T->len = 0;
	fd = open(argv[1], O_RDONLY);
	T->line = get_next_line(fd);
	if (!T->line)
	{
		write(1, "can't read the file", 20);
		exit(0);
	}
	while (T->line)
	{
		T->len++;
		T->line = get_next_line(fd);
	}
	free(T->line);
	close(fd);
}

void	ft_fillmap(char **argv, t_map *T)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	T->map = malloc(sizeof(char *) * T->len + 1);
	if (!T->map)
	{
		write(1, "Error\ncheck the malloc", 17);
		exit(0);
	}
	i = 0;
	line = get_next_line(fd);
	if (!line)
		error("Error\ncan't read the file");
	while (line)
	{
		T->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	T->map[i] = NULL;
}

void	check_column_length(t_map *T)
{
	size_t	len;
	int		i;

	len = ft_strlen(T->map[0]);
	i = 1;
	while (T->map[i])
	{
		if ((ft_strlen(T->map[i]) != len && i < (T->len - 1))
			|| (i == (T->len - 1) && ft_strlen(T->map[i]) != (len - 1)))
		{
			error("Error\nthe map doesn't have the same length");
		}
		i++;
	}
	i = 0;
	while (T->map[i])
	{
		if (T->map[i][0] != '1' || T->map[i][len - 2] != '1')
		{
			write(1, "Error\ninvalide map", 19);
			exit(0);
		}
		i++;
	}
}

void	check_f_l_line(t_map *T)
{
	int	i;
	int	j;

	j = 0;
	while (T->map[j])
	{
		i = 0;
		while (T->map[j][i] && T->map[j][i] != '\n')
		{
			if (j == 0 || j == (T->len - 1))
			{
				if (T->map[j][i] != '1')
				{
					write(1, "Error\nI Can't find some stuff", 30);
					exit(0);
				}
			}
				i++;
		}
		j++;
	}
}
