/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:43:41 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/21 16:35:56 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	getlen_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

int	contains_newline(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

char	*extract_line(char *str, char **leftover)
{
	int		size;
	int		i;
	char	*line;

	size = getlen_line(str);
	if (size == 0)
		return (NULL);
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, size + 1);
	i = size;
	while (str[size])
		size++;
	*leftover = malloc((size - i) + 1);
	if (!*leftover)
		return (NULL);
	ft_strlcpy(*leftover, str + i, (size - i) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*string;
	char		*tmp;
	char		*buff;
	size_t		rd_bytes;
	static char	*leftover[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, leftover[fd], 0) == -1)
		return (NULL);
	string = leftover[fd];
	leftover[OPEN_MAX] = NULL;
	rd_bytes = BUFFER_SIZE;
	while (rd_bytes == BUFFER_SIZE && !contains_newline(string))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		buff[rd_bytes] = '\0';
		string = ft_strjoin(string, buff);
	}
	tmp = extract_line(string, &leftover[fd]);
	free(string);
	return (tmp);
}
