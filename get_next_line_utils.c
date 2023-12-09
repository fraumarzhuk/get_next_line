/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariannazhukova <mariannazhukova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:39:07 by mariannazhu       #+#    #+#             */
/*   Updated: 2023/12/09 01:39:21 by mariannazhu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (*s1)
	{
		result[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		result[i++] = *s2;
		s2++;
	}
	result[i++] = '\0';
	return (result);
}

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
	int	*p;

	p = malloc(count * size);
	if (p != NULL)
		ft_memset(p, 0, count * size);
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (src == NULL)
		return (0);
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (i < (dstsize - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, s1, (ft_strlen(s1) + 1));
	return (p);
}