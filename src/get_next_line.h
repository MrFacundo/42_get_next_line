/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:34 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/30 21:35:18 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc
# include <unistd.h> // read
# include <stdio.h> // printf, to remove later

# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

// char	*get_next_line(int fd);
// void	fd_to_stash(int fd, t_list **stash);
// void	stash_to_line(char **line, t_list *stash);
// char	*newline_in_stash(t_list *stash);
// void	allocate_line(char **line, t_list *stash);
// void	remove_line_from_stash(t_list **stash);
// void	free_stash(t_list *stash);
// t_list	*ft_lstnew(char *content);
// t_list	*ft_lstlast(t_list *lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// char	*ft_strdup(const char *s);
// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);

#endif