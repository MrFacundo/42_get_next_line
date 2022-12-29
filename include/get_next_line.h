/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:34 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/29 14:29:58 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc
# include <unistd.h> // read
#include <stdio.h> // printf, to remove later



# define ERROR_CHECK(x) if (x) return (0)
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}				t_list;


char	*get_next_line(int fd);
int		fd_to_stash(int fd, t_list **stash);
int 	stash_to_line(char **line, t_list *stash);
void	add_buffer_to_stash(t_list **stash,char *buffer, int chars_read);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	allocate_line(char **line, t_list *stash);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*newline_in_stash(t_list *stash);
void	remove_line_from_stash(t_list **stash);
void	free_stash(t_list *stash);









#endif