/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:11:08 by mariannazhu       #+#    #+#             */
/*   Updated: 2023/12/09 18:12:06 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_start(const char *remainer)
{
	int		len;
	char	*start;
	char	*temp;

	len = 0;
	while (remainer[len] != '\n' && remainer[len] != '\0')
		len++;
	start = malloc(len + 1);
	if (!start)
		return (NULL);
	temp = start;
	while (*remainer != '\n' && *remainer != '\0')
	{
		*temp = *remainer;
		temp++;
		remainer++;
	}
	*temp = '\n';
	temp++;
	*temp = '\0';
	return (start);
}

char	*get_remainer(const char *remainer)
{
	char	*end;
	char	*temp;
	int		n;

	n = 0;
	while (remainer[n] != '\n' && remainer[n] != '\0')
		n++;
	if (remainer[n] == '\0' || remainer[n + 1] == '\0')
		return (NULL);
	end = malloc(ft_strlen(remainer) - n + 1);
	if (!end)
		return (NULL);
	temp = end;
	remainer += n + 1;
	while (*remainer != '\0')
	{
		*temp++ = *remainer++;
		n++;
	}
	*temp = '\0';
	return (end);
}

char	*read_and_store(char *buffer, char **remainer)
{
	char	*res;
	char	*temp;
	char	*new_remainer;

	res = NULL;
	if (*remainer == NULL) //If there is no remainer
		*remainer = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(*remainer, buffer);
		free(*remainer);
		*remainer = temp;
	}
	if (!*remainer)
		return (NULL);
	if (ft_strrchr(*remainer, '\n') == NULL)
		return (NULL);
	else
	{
		res = get_start(*remainer);
		new_remainer = get_remainer(*remainer);
		free(*remainer);
		*remainer = new_remainer;
		return (res);
	}
}

char	*process_remainder(char **remainer)
{
	char	*res;

	if (*remainer != NULL && **remainer != '\0')
	{
		res = ft_strdup(*remainer);
		free(*remainer);
		*remainer = NULL;
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainer;
	char		buffer[BUFFER_SIZE + 1];
	char		*res;
	size_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		res = read_and_store(buffer, &remainer);
		if (res != NULL)
			return (res);
	}
	return (process_remainder(&remainer));
}


// #include <stdio.h>

// int main()
// {
// 	char	*res;
// 	int	fd = open("text.txt", O_RDONLY);

// 	if (fd < 0)
// 		printf("File not open \n");

// 	res = get_next_line(fd);
// 	printf("Res1: %s", res);
// 	res = get_next_line(fd);
// 	printf("Res2: %s", res);
// 	res = get_next_line(fd);
// 	printf("Res3: %s", res);
// }
