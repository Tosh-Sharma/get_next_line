/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:41:56 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/06 15:26:46 by tsharma          ###   ########.fr       */
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
char	*ft_calloc(int count, int size);
char	*cpy_and_reset_src(char *src);
char	*break_line(char *line, char *extra, int position);
char	*handle_end(char *buffer, char *line);
char	*handle_read(char *line, char *buffer, char *extra, int fd);
char	*get_next_line(int fd);

#endif
