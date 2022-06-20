/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:48:58 by tsharma           #+#    #+#             */
/*   Updated: 2022/06/20 18:29:46 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <stdio.h>

int	init(void)
{
	static int	count = 0;
	count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			res = (char *)&s[i];
			return (res);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		res = (char *)&s[i];
		return (res);
	}
	return (NULL);
}

void	send_line(t_list **list)
{
}

void	break_line

void	traverse_file(int fd, t_list **list)
{
	char	*buff;
	int		read_count;
	char	*extra;
	char	*line;

	while (read_count != 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_count = read(fd, buff, BUFFER_SIZE + 1);
		printf("Read count is %d\n", read_count);
		printf("Buff output is %s\n", buff);
		if (ft_strchr(buff, '\n') == 1)
		{
			break_line(line, extra, buff);
			ft_lstadd_back(list, ft_lstnew(line));
		}
		// Above break line is made to store extra in extra, add the necessary
		// part to line (along with the existing stuff)
		// and to have the required length of the code.
	}
}

void	get_next_line(int fd)
{
	t_list	**list;

	if (init() == 1)
		traverse_file(fd, list);
	send_line(list);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
	}
	close(fd);
}
