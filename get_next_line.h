/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:41:56 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/05 17:03:14 by tsharma          ###   ########.fr       */
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
char	*ft_strjoin_and_free(char const *s1, char const *s2);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_calloc(int count, int size);
char	*break_line(char *line, char *extra, int position);

#endif
