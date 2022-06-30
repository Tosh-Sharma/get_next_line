/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/06/30 10:30:02 by tsharma          ###   ########.fr       */
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

char	*cpy_and_erase_src(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	src[0] = '\0';
	return (dst);
}

char	*break_line(char *buffer, char *line, char *extra, int position)
{
	int		i;
	int		j;
	char	temp[BUFFER_SIZE + 1];
	char	*new_line;

	i = 0;
	while (i <= position)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	new_line = ft_strjoin(line, temp);
	free(line);
	j = 0;
	while (j <= BUFFER_SIZE)
	{
		extra[j] = buffer[j + i];
		j++;
	}
	extra[j] = '\0';
	return (new_line);
}

char	*break_multi_lines(char *line, char *extra, int position)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(sizeof(char) * (position + 1));
	while (i <= position)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	i = 0;
	while (i < (ft_strlen(line) - position))
	{
		extra[i] = line[position + 1 + i];
		i++;
	}
	extra[i] = '\0';
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			read_count;
	char		*line;
	static char	extra[BUFFER_SIZE + 1];
	char		*new_line;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = cpy_and_erase_src(extra);
	read_count = 1;
	while (ft_strchr(line, '\n') != -1 || read_count != 0)
	{
		if (ft_strchr(line, '\n') != -1)
			return (break_multi_lines(line, extra, ft_strchr(line, '\n')));
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n') != -1)
			return (break_line(buffer, line, extra, ft_strchr(buffer, '\n')));
		else
		{
			new_line = ft_strjoin(line, buffer);
			free(line);
			line = new_line;
		}
	}
	return (line);
}
