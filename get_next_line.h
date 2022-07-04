/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:41:56 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/04 18:28:08 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(const char *s, int c);
char	*ft_strjoin_and_free(char const *line, char const *buffer);
char	*ft_strdup(char *src);
int		ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);

#endif
