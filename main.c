/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:49:20 by toshsharma        #+#    #+#             */
/*   Updated: 2022/07/06 14:48:57 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;

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
		printf("Line received is \"%s\"\n", get_next_line(fd));
	}
	close(fd);
}
