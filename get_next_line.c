/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/06/22 16:54:29 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*append_line(char *buffer, char *line, char *extra)
{
	char	*new_line;

	if (extra != NULL)
	{
		new_line = ft_strjoin(extra, line);
		// free(extra);
		// This printf is to find out if we freed it and
		// the output is NULL or what?
		printf("Extra is %s\n", extra);
	}
	if (buffer != NULL)
		new_line = ft_strjoin(line, buffer);
	return (new_line);
}

char	*break_line(char *buffer, char *line, char *extra, int position)
{
	int		iter;
	char	temp[BUFFER_SIZE + 1];
	char	*new_line;

	iter = 0;
	while (iter <= position)
	{
		temp[iter] = buffer[iter];
		iter++;
	}
	temp[iter] = '\0';
	printf("Temp is %s\n--------\n", temp);
	printf("Line before join is %s\n------\n", line);
	new_line = ft_strjoin(line, temp);
	printf("Line after join is %s", new_line);
	iter = 0;
	while (iter < BUFFER_SIZE + 1)
	{
		extra[iter] = buffer[position + 1 + iter];
		iter++;
	}
	extra[iter] = '\0';
	printf("Extra is %s\n-------\n", extra);
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
	read_count = -1;
	line = 0;
	while (read_count != 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE + 1);
		printf("Buffer read %s \n--------------------\n", buffer);
		position = ft_strchr(buffer, '\n');
		printf("position is %d\n", position);
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
