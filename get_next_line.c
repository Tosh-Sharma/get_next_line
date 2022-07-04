/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/04 19:29:51 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = b;
	while (i < len)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char	*cpy_and_reset_src(char *src)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!res)
		return (NULL);
	while (src[i] != '\0')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	ft_memset(src, 0, BUFFER_SIZE + 1);
	return (res);
}

//	Line can be null. Buffer can also be null 
char	*break_line(char *line, char *extra, char *buffer, int position)
{
	int		i;
	char	temp[BUFFER_SIZE + 1];
	char	*res;

	i = 0;
	while (i <= position)
	{
		if (buffer != NULL)
			temp[i] = buffer[i];
		else
			temp[i] = line[i];
		i++;
	}
	temp[i] = '\0';
	if (line != NULL)
		res = ft_strjoin_and_free(line, temp);
	else
		res = ft_strdup(temp);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (buffer != NULL)
			extra[i] = buffer[position + i];
		else
			extra[i] = line[position + i];
		i++;
	}
	extra[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	int			read_count;
	char		*line;
	char		*buffer;
	static char	extra[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = cpy_and_reset_src(extra);
	read_count = 1;
	while (read_count > 0 || ft_strchr(extra, '\n') != -1)
	{
		if (ft_strchr(line, '\n') != -1)
			return (break_line(line, extra, NULL, ft_strchr(line, '\n')));
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n') != -1)
			return (break_line(line, extra, buffer, ft_strchr(buffer, '\n')));
		else
			line = ft_strjoin_and_free(line, buffer);
	}
	return (line);
}
