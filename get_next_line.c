/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/06/21 17:48:24 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	append_line(char *buffer, char *line, char *extra)
{
	char	*new_line;

	if (extra != NULL)
	{
		new_line = ft_strjoin(extra, line);
		free(extra);
		// This printf is to find out if we freed it and
		// the output is NULL or what?
		printf("Extra is %s\n", extra);
	}
	if (buffer != NULL)
		new_line = ft_strjoin(line, buffer);
	return (new_line);
}

void	break_line(char *buffer, char *line, char *extra, int position)
{
	int	buffer_len;

	buffer_len = ft_strlen(buffer);
	extra = malloc(sizeof(char) * (buffer_len - position));
	// Copy stuff into extra.
	// Add stuff into line and free the stuff correctly.
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			read_count;
	char		*line;
	static char	*extra;
	int			position;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read_count != 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE + 1);
		position = ft_strchr(buffer, '\n');
		if (position != -1)
		{
			break_line(buffer, line, extra, position);
			return (line);
		}
		else
			line = append_line(buffer, line, extra);
	}
}
