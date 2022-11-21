/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:22:15 by nibenoit          #+#    #+#             */
/*   Updated: 2022/11/21 15:47:54 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);

	printf("%d\n", fd1);
	int	i = 1;
	int	j = 1;
	int k = 1;
	
		line = get_next_line_bonus(fd1);
		printf("line [%d]: %s\n", i, line);
		free(line);
		i++;

		line = get_next_line_bonus(fd2);
		printf("line [%d]: %s\n", j, line);
		free(line);
		j++;

		line = get_next_line_bonus(fd1);
		printf("line [%d]: %s\n", i, line);
		free(line);
		i++;

		line = get_next_line_bonus(fd3);
		printf("line [%d]: %s\n", k, line);
		free(line);
		k++;

		line = get_next_line_bonus(fd2);
		printf("line [%d]: %s\n", j, line);
		free(line);
		j++;

		line = get_next_line_bonus(fd1);
		printf("line [%d]: %s\n", i, line);
		free(line);
		i++;

	close(fd1);
	close(fd2);
	close(fd3);
	
	return (0);
}