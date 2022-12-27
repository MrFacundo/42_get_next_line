/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:34 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/27 23:39:36 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc
# include <unistd.h> // read



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
void stash_to_line(char **line, t_list *stash);
void	add_buffer_to_stash(t_list **stash,char *buffer, int chars_read);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	get_line_length(char **line, t_list *stash);




#endif