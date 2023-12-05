/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:09 by mzhukova          #+#    #+#             */
/*   Updated: 2023/12/05 13:33:05 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#define BUFFER_SIZE 1024  // Size of the buffer

char	*get_next_line(int fd)
{
	char	*buffer;
	static char *p;
	static char *temp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	p = temp;
	while (*buffer != '\n' || *buffer != '\0')
	{
		temp = buffer;
		temp++;
		buffer++;
	}
	temp++;
	free(buffer);
	return (p);
}

#include <stdio.h>

int main ()
{
	char *res = get_next_line(0);
	printf("Result: %s \n", res);
	return (0);
}