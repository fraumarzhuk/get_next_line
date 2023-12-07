/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:09 by mzhukova          #+#    #+#             */
/*   Updated: 2023/12/07 16:20:36 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*read_and_store(char *buffer, int fd)
{
	char	*res;
	int		i;

	i = 1;
	res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[0] = buffer[0];
	while (read(fd, buffer, 1) > 0 && buffer[0] != '\0'
		&& buffer[0] != '\n' && i < BUFFER_SIZE)
	{
		if (*buffer != '\n')
			res[i] = buffer[0];
		i++;
	}
	if (buffer[0] == '\0')
	{
		free(res);
		return (NULL);
	}
	if (buffer[0] == '\n')
		res[i] = '\n';
	res[BUFFER_SIZE] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	size_t		bytes_read;
	char		*res;

	bytes_read = read(fd, buffer, 1);
	if (!(fd < 0) && BUFFER_SIZE > 0 && bytes_read > 0)
	{
		res = read_and_store(buffer, fd);
		return (res);
	}
	return (NULL);
}

// #include <stdio.h>
// int main ()
// {
// 	int		fd;

// 	// fd = open("baal.txt", O_RDONLY);
// 	fd = 0;
// 	char *res = get_next_line(fd);
// 	printf("Res: %s", res);
// 	res = get_next_line(fd);
// 	printf("Res2: %s", res);
// 	res = get_next_line(fd);
// 	printf("Res2: %s", res);
// 		res = get_next_line(fd);
// 	printf("Res2: %s", res);
// }
