/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:37 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/27 23:42:14 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	static t_list	*stash = NULL;
	// check errors (fd, buffer, file is readeable fd)
	read_fd(fd, &stash);
	stash_to_line(stash, line);
	return (line);
}

void read_fd(int fd, t_list **stash)
{
	char *buffer;
	int chars_read;

	buffer = malloc(BUFFER_SIZE);
	// check errors (malloc)
	chars_read = read(fd, buffer, BUFFER_SIZE);
	// check errors (if file is empty or error while reading)
	buffer[chars_read] = '\n';
	add_buffer_to_stash(stash, buffer, chars_read);
	free(buffer);
}

void add_buffer_to_stash(t_list **stash, char *buffer, int chars_read)
{
	t_list *new_node;

	new_node = ft_lstnew(buffer);

	ft_lstadd_back(stash, new_node);
}

void stash_to_line(char **line, t_list *stash)
{
	// calculate line length;

	get_line_length(line, stash);
	if (*line == NULL)
		return;
	while (stash)
	{
		while (*stash->content)
		{
			*line = *stash->content;
			line++;
			stash->content++;
		}
		stash = stash->next;
	}
	*line = '\0';
}
