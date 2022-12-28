/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:34 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/28 20:28:32 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc
# include <unistd.h> // read
#include <stdio.h> // printf, to remove later




# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}				t_list;


char	*get_next_line(int fd);
void	read_fd(int fd, t_list **stash);
void 	stash_to_line(char **line, t_list *stash);
void	add_buffer_to_stash(t_list **stash,char *buffer, int chars_read);
t_list	*ft_lstnew(char *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	get_line_pointer(char **line, t_list *stash);
char		*ft_strdup(const char *s);
size_t		ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
int newline_in_stash(t_list *stash);
void	remove_line_from_stash(t_list **stash);
void	free_stash(t_list *stash);









#endif