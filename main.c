/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:49:20 by toshsharma        #+#    #+#             */
/*   Updated: 2022/06/30 10:16:11 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd != -1)
	{
		// get_next_line(fd);
		// get_next_line(fd);
		// get_next_line(fd);
		// get_next_line(fd);
		// get_next_line(fd);
		// get_next_line(fd);
		// get_next_line(fd);

		printf("Line received is \"%s\"\n",get_next_line(fd));
		printf("Line received is \"%s\"\n",get_next_line(fd));
		printf("Line received is \"%s\"\n",get_next_line(fd));
		printf("Line received is \"%s\"\n",get_next_line(fd));
		printf("Line received is \"%s\"\n",get_next_line(fd));
		printf("Line received is \"%s\"\n",get_next_line(fd));
		printf("Line received is \"%s\"\n",get_next_line(fd));
	}
	close(fd);
}
