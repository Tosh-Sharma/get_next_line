/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:39:49 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/04 16:55:24 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
