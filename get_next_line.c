/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:09 by mzhukova          #+#    #+#             */
/*   Updated: 2023/12/08 16:52:04 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif


#include <string.h> 

char	*find_n(char *cur_line, char *line_left)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (strchr(cur_line, '\n') == 0)
	{
		line_left = ft_strjoin(line_left, cur_line);
		return (line_left);
	}
	while (cur_line[i] != '\n')
	{
		*res = cur_line[i];
		i++;
		res++;
	}
	*res = '\n';
	while (*line_left != '\0')
		line_left++;
	while (cur_line[i] != '\0')
	{
		*line_left = cur_line[i];
		line_left++;
		i++;
	}
	return (NULL);
}

char	*line_check(char *buffer, char *line_left)
{
	char	*res;

	if (*line_left == '\0')
		res = find_n(buffer, line_left);

	else
	{
		res = ft_strjoin(line_left, buffer);
		res = find_n(line_left, line_left);
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	static char		*line_left;
	char			*res;
	size_t			bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (!(fd < 0) && BUFFER_SIZE > 0 && bytes_read > 0)
	{
		res = line_check(buffer, line_left);
		while (strchr(res, '\n') == 0)
		{
			res = get_next_line(fd);
		}
		return (res);
	}
	return (NULL);

}

#include <stdio.h>
int main (int argc, char **argv)
{
	int		fd;
	(void) argc;

	fd = open(argv[1], O_RDONLY);
	char *res = get_next_line(fd);
	printf("Res: %s", res);
	res = get_next_line(fd);
	printf("Res2: %s", res);
	res = get_next_line(fd);
	printf("Res2: %s", res);
		res = get_next_line(fd);
	printf("Res2: %s", res);
}
