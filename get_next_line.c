/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:09 by mzhukova          #+#    #+#             */
/*   Updated: 2023/12/06 19:46:28 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


ssize_t	read_char(int fd, char *buffer)
{
	return (read(fd, buffer, 1));
}

char	*process_remainder(char **remainder)
{
	char	*line;
	char	*newline_pos;
	char	*new_remainder;

	line = NULL;
	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*remainder);
		new_remainder = ft_strdup(newline_pos + 1);
		free(*remainder);
		*remainder = new_remainder;
	}
	else
	{
		line = *remainder;
		*remainder = NULL;
	}
	return (line);
}

char	*handle_end(ssize_t bytes_read, char *line)
{
	if (bytes_read < 0)
	{
		free(line);
		return (NULL);
	}
	if (bytes_read == 0 && !line)
		return (NULL);
	return (line);
}

char	*read_and_store(int fd, char **remainder, char *line)
{
	char	buffer[2];
	ssize_t	bytes_read;

	bytes_read = read_char(fd, buffer);
	while (bytes_read > 0)
	{
		buffer[1] = '\0';
		if (buffer[0] == '\n')
		{
			*remainder = ft_append(*remainder, '\0');
			break ;
		}
		line = ft_append(line, buffer[0]);
		if (line)
			return (NULL);
		bytes_read = read_char(fd, buffer);
	}
	return (handle_end(bytes_read, line));
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	line = NULL;
	if (remainder)
	{
		line = process_remainder(&remainder);
		if (line)
			return (line);
	}
	return (read_and_store(fd, &remainder, line));
}

#include <stdio.h>
int main ()
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	char *res = get_next_line(fd);
	printf("Res: %s", res);
	res = get_next_line(fd);
	printf("Res2: %s", res);
		res = get_next_line(fd);
	printf("Res2: %s", res);

}


// Reading the file into the buffer, until reaching \n
// Saving the value read from the previous action into the char* (get line)
// Saving the remained buffer into remainer
// Repeat