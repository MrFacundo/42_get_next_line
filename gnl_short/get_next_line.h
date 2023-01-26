/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:34 by ftroiter          #+#    #+#             */
/*   Updated: 2023/01/02 21:33:05 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc
# include <unistd.h> // read
# include <stdio.h> // FOPEN_MAX, printf

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* get_next_line.c */
char	*get_next_line(int fd);

#endif