/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toshsharma <toshsharma@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:49:20 by toshsharma        #+#    #+#             */
/*   Updated: 2022/05/31 14:48:04 by toshsharma       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *res;

    fd = open("testfile.txt", O_RDONLY);
    if (fd != -1)
    {
        res = get_next_line(fd);
        printf("\nThe Result is \n");
        printf("%s", res);
        res = get_next_line(fd);
        printf("\nThe Result is \n");
        printf("%s", res);
    }
    close(fd);
}