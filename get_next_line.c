/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/05 17:32:33 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	src[0] = '\0';
	return (res);
}

char	*break_line(char *line, char *extra, int position)
{
	int		i;
	int		length;
	char	*temp;

	i = 0;
	temp = ft_calloc(position + 2, sizeof(char));
	while (i <= position)
	{
		temp[i] = line[i];
		i++;
	}
	temp[i] = '\0';
	i = 0;
	length = ft_strlen(line);
	while (i < length - position)
	{
		extra[i] = line[position + 1 + i];
		i++;
	}
	extra[i] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	int			read_count;
	char		*line;
	char		*buffer;
	static char	extra[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = cpy_and_reset_src(extra);
	read_count = 1;
	while (read_count > 0 || ft_strchr(line, '\n') != -1)
	{
		if (ft_strchr(line, '\n') != -1)
			return (break_line(line, extra, ft_strchr(line, '\n')));
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n') != -1)
		{
			line = ft_strjoin_and_free(line, buffer);
			return (break_line(line, extra, ft_strchr(line, '\n')));
		}
		else
			line = ft_strjoin_and_free(line, buffer);
	}
	return (line);
}
