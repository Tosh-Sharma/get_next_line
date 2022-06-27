/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/06/27 16:20:58 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*append_line(char *buffer, char *line, char *extra)
{
	char	*new_line;

	if (extra != NULL)
		new_line = ft_strjoin(extra, line);
	if (buffer != NULL)
		new_line = ft_strjoin(line, buffer);
	return (new_line);
}

char	*cpy_and_erase_src(char *dst, char *src)
{
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * (n + 1));
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (i < BUFFER_SIZE)
	{
		src[i] = '\0';
		i++;
	}
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
	new_line = malloc(sizeof(char) * (ft_strlen(line) - position));
	while (i <= position)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	i = 0;
	while (i <= ft_strlen(line - position))
	{
		extra[i] = line[position + i];
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
	int			position;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = cpy_and_erase_src(line, extra);
	while (1)
	{
		if (ft_strchr(line, '\n') != -1)
		{
			line = break_multi_lines(line, extra, ft_strchr(line, '\n'));
			return (line);
		}
		read_count = read(fd, buffer, BUFFER_SIZE + 1);
		printf("Buffer is \"%s\"\n", buffer);
		position = ft_strchr(buffer, '\n');
		if (position != -1)
		{
			line = break_line(buffer, line, extra, position);
			return (line);
		}
		else
			line = append_line(buffer, line, extra);
	}
	return (NULL);
}
