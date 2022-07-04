/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:41:56 by tsharma           #+#    #+#             */
/*   Updated: 2022/07/04 16:04:32 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

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
char	*cpy_and_reset_src(char *src);
char	*break_line(char *line, char *extra, char *buffer, int position);
char	*get_next_line(int fd);

#endif
