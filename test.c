/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:48 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/04 17:52:23 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			res = (char *)&s[i];
			return (i);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		res = (char *)&s[i];
		return (i);
	}
	return (-1);
}

static char	*joiner(char const *line, char const *buffer)
{
	int		total_size;
	char	*res;
	int		i;
	int		j;

	total_size = ft_strlen(line) + ft_strlen(buffer) + 1;
	res = (char *)malloc(sizeof(char) * total_size);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(line))
	{
		res[i] = line[i];
		i++;
	}
	while (j < ft_strlen(buffer))
	{
		res[i + j] = buffer[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*ft_strjoin_and_free(char const *line, char const *buffer)
{
	char	*new_line;

	if (line == NULL && buffer == NULL)
		return (NULL);
	if (line == NULL)
		return (ft_strdup((char *)buffer));
	else if (buffer == NULL)
	{
		new_line = ft_strdup((char *)line);
		free((void *)line);
		return (new_line);
	}
	else
	{
		new_line = joiner(line, buffer);
		free((void *)line);
		return (new_line);
	}
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
	int		j;
	char	temp[BUFFER_SIZE + 1];
	char	*res;

	i = 0;
	while (i <= position)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	if (line != NULL)
		res = ft_strjoin_and_free(line, temp);
	else
		res = ft_strdup(temp);
	j = 0;
	while (j <= BUFFER_SIZE)
	{
		extra[j] = buffer[i + j];
		j++;
	}
	extra[j] = '\0';
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
			return (break_line(NULL, extra, NULL, ft_strchr(line, '\n')));
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

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		printf("Line received is \"%s\"\n", get_next_line(fd));
		printf("Line received is \"%s\"\n", get_next_line(fd));
		printf("Line received is \"%s\"\n", get_next_line(fd));
		printf("Line received is \"%s\"\n", get_next_line(fd));
		printf("Line received is \"%s\"\n", get_next_line(fd));
		printf("Line received is \"%s\"\n", get_next_line(fd));
		printf("Line received is \"%s\"\n", get_next_line(fd));
	}
	close(fd);
}
