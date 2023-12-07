/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhukova <mzhukova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:44:29 by mzhukova          #+#    #+#             */
/*   Updated: 2023/12/07 15:39:27 by mzhukova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*b;

	b = (unsigned char *) str;
	while (len--)
	{
		*b++ = (unsigned char) c;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p != NULL)
		ft_memset(p, 0, count * size);
	return (p);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!*s)
// 		return (0);
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strcpy(char *dest, const char *src)
// {
// 	char	*start;

// 	start = dest;
// 	while (*src != '\0')
// 	{
// 		*dest = *src;
// 		dest++;
// 		src++;
// 	}
// 	*dest = '\0';
// 	return (start);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	char	ch;

// 	ch = (char)c;
// 	while (*s != ch)
// 	{
// 		if (*s == '\0')
// 			return (NULL);
// 		s++;
// 	}
// 	return ((char *)s);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*p;

// 	p = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
// 	if (p == NULL)
// 		return (NULL);
// 	ft_strcpy(p, s1);
// 	return (p);
// }

// char	*ft_append(char *str, char c)
// {
// 	char	*new_str;
// 	size_t	len;

// 	len = ft_strlen(str);
// 	new_str = malloc(len + 2);
// 	if (!new_str)
// 		return (NULL);
// 	if (str)
// 		ft_strcpy(new_str, str);
// 	new_str[len] = c;
// 	new_str[len + 1] = '\0';
// 	free(str);
// 	return (new_str);
// }