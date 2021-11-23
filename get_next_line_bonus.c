/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:11:45 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/11/22 21:02:14 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	has_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_line(int fd)
{
	char	*buff;
	char	*hold;
	int		x;

	hold = ft_calloc(1, sizeof(char));
	if (!hold)
		return (0);
	x = 1;
	while (x > 0 && has_nl(hold) == -1)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (0);
		buff[BUFFER_SIZE] = 0;
		x = read(fd, buff, BUFFER_SIZE);
		hold = ft_strjoin(hold, buff);
	}
	return (hold);
}

char	*get_next_line(int fd)
{
	static char	*remain[1024];
	char		*buff;
	char		*hold;

	if (read(fd, NULL, 0) < 0)
		return (0);
	buff = read_line(fd);
	if (remain[fd])
	{
		buff = ft_strjoin(remain[fd], buff);
		remain[fd] = 0;
	}
	if (has_nl(buff) != -1)
	{
		remain[fd] = ft_strdup(buff + has_nl(buff) + 1);
		hold = ft_substr(buff, 0, has_nl(buff) + 1);
		return (hold);
	}
	if (!(*buff))
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
