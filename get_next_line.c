/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:47:47 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/18 14:35:05 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

#include <fcntl.h>
#include <stdio.h>

int	contains_newline(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		if (s[i++] == '\n')
			return (1);
	return (0);
}

size_t	getline_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*extract_line(char *s, char **leftover)
{
	size_t	i;
	size_t	size;
	char	*line;

	size = getline_len(s);
	if (size == 0)
		return (NULL);
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, s, size + 1);
	i = size;
	while (s[size])
		size++;
	*leftover = malloc((size - i) + 1);
	if (!*leftover)
		return (NULL);
	ft_strlcpy(*leftover, s + i, (size - i) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*tmp;
	char		*string;
	size_t		ret;
	static char	*leftover = NULL;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, leftover, 0) == -1)
		return (NULL);
	ret = BUFFER_SIZE;
	string = leftover;
	while (ret == BUFFER_SIZE && !contains_newline(string))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		string = ft_strjoin(string, buff);
	}
	tmp = extract_line(string, &leftover);
	free(string);
	return (tmp);
}

// int	main(void)
// {
// 	int		fd1;
// 	char	*line;
// 	fd1 = open("test.txt", O_RDONLY);
// 	printf("%d\n", fd1);
// 	int	i = 1;

// 	while (i < 7)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%d]: %s\n", i, line);
// 		free(line);
// 		i++;

// 	}
// 	close(fd1);
// 	return (0);
// }
