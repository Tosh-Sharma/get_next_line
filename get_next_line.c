/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+      +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:03:25 by toshsharma        #+#    #+#             */
/*   Updated: 2022/05/30 16:57:00 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *get_next_line(int fd)
{
    int         read_count;
    static char *buff;

    buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    read_count = read(fd, buff, BUFFER_SIZE + 1);
    printf("%d", read_count);
    printf("%s", buff);
    return (buff);
}

