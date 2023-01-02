/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:24:17 by facu              #+#    #+#             */
/*   Updated: 2023/01/02 00:06:09 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> // malloc
# include <unistd.h> // read
# include <stdio.h> // FOPEN_MAX, printf
// # include <limits.h> // OPEN_MAX

# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* get_next_line_bonus.c */
char	*get_next_line(int fd);

/* get_next_line_bonus_utils.c */
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif