/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:37 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/28 20:49:40 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	static t_list *stash = NULL;
	// check errors (fd, buffer, file is readeable fd)
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_fd(fd, &stash);
	stash_to_line(&line, stash);
	remove_line_from_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void read_fd(int fd, t_list **stash)
{
	char *buffer;
	int chars_read;

	chars_read = 1;
	while (!newline_in_stash(*stash) && chars_read)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		// check errors (malloc)
		chars_read = read(fd, buffer, BUFFER_SIZE);

		// check errors (if file is empty or error while reading)
		buffer[chars_read] = '\0';
		add_buffer_to_stash(stash, buffer, chars_read);
		free(buffer);
	}
}

void add_buffer_to_stash(t_list **stash, char *buffer, int chars_read)
{
	t_list *new_node;
	char *content;

	content = ft_strdup(buffer);



	new_node = ft_lstnew(content);

	ft_lstadd_back(stash, new_node);
	// printf("lastnpode->content: %s\n", ft_lstlast(*stash)->content);

}

void stash_to_line(char **line, t_list *stash)
{
	// calculate line length;

	int i;
	int j;
	get_line_pointer(line, stash);

	if (!*line)
		return;
	j = 0;

	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
	// printf("line: %s\n", *line);

}

void remove_line_from_stash(t_list **stash)
{
	t_list *last;
	t_list *new_node;
	char *clean_content;
	int i;

	last = ft_lstlast(*stash);
	i = 0;
	// printf("abc %s", last->content);

	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	// printf("%s", last->content);
	clean_content = ft_strdup(&last->content[i]);

	new_node = ft_lstnew(clean_content);

	free_stash(*stash);
	*stash = new_node;
}
