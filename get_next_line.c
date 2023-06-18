/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:41:57 by asaouab           #+#    #+#             */
/*   Updated: 2023/06/16 17:08:00 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_pointline_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_after_newline(char *stock)
{
	char	*temp;
	int		a;
	int		i;

	i = 0;
	while (stock[i] != '\n')
	{
		if (stock[i] == '\0')
			return (free(stock), NULL);
		i++;
	}
	a = i + 1;
	while (stock[i] != '\0')
		i++;
	temp = ft_substr(stock, a, i - a);
	free(stock);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stock;
	char		*line;
	int			a;

	a = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(stock, '\n') == 0 && a > 0)
	{
		a = read (fd, buffer, BUFFER_SIZE);
		if (a == -1)
			return (free (stock), free (buffer), NULL);
		buffer[a] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	line = ft_substr(stock, 0, ft_pointline_len(stock) + 1);
	stock = get_after_newline(stock);
	return (line);
}
