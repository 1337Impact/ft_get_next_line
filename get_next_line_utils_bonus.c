/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:26:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/22 19:42:20 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	int		l;

	substr = (char *)malloc(len + 1);
	i = 0;
	l = (int)len;
	if (substr == NULL)
	{
		return (NULL);
	}
	while (i < l)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = 0;
	free((void *)s);
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;
	int		i;
	int		j;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	join = (char *)malloc(size + 1);
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i++] = s2[j++];
	}
	join[i] = 0;
	free((void *)s1);
	free((void *)s2);
	return (join);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	int		i;
	int		a;
	char	*array;

	array = (char *)s;
	i = 0;
	a = (int)n;
	while (i < a)
	{
		array[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*out;

	out = malloc(count * size);
	if (out == NULL)
	{
		return (NULL);
	}
	ft_bzero(out, count * size);
	return ((void *)out);
}
