/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:37 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/30 01:32:10 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/*	1. read and stash
	2. dumps stash into allocated line
	3. resets stash so that it begins after the extracted line
	4. free memory when EOF */
char *get_next_line(int fd)
{
	char *line;
	static t_list *stash = NULL;
	/* EC on open function in main() || the fd ain't readeable
	|| the buffer set on compilation is invalid */
	ERROR_CHECK(fd < 0 || read(fd, &line, 0) < 0
		||  BUFFER_SIZE <= 0 || BUFFER_SIZE > MAX_FILE_DESCRIPTOR);
	fd_to_stash(fd, &stash); // 1.
	ERROR_CHECK(!stash); // EC file is empty
	stash_to_line(&line, stash); // 2. 
	remove_line_from_stash(&stash); // 3.
	if (line[0] == '\0') // 4. 
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (0);
	}
	return (line);
}

/* until a newline is found on the stash or no chars
are read: reads file descriptor into a buffer, a BUFFER_SIZE
amount of bytes, nul terminates buffer and adds it to a stash */
int fd_to_stash(int fd, t_list **stash)
{
	char *buffer;
	int chars_read;

	chars_read = 1;
	while (!newline_in_stash(*stash) && chars_read)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		ERROR_CHECK(!buffer);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		/*	EC file is empty || can't read() fd */
		if ((!*stash && !chars_read) || chars_read < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[chars_read] = '\0';
		add_buffer_to_stash(stash, buffer);
		free(buffer);
	}
	return (1);
}

/* adds a node with a duplicate of the buffer
as content to the end of the stash */
void add_buffer_to_stash(t_list **stash, char *buffer)
{
	t_list *new_node;

	new_node = ft_lstnew(ft_strdup(buffer));
	ft_lstadd_back(stash, new_node);
}

/* allocates a line and dumps the stash content into it*/
int stash_to_line(char **line, t_list *stash)
{
	int i;
	int j;

	allocate_line(line, stash);
	ERROR_CHECK(!*line);
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
	return 1;
}

/* resets stash so it begins after the extracted line
nul char is added to signal EOF */ 
void remove_line_from_stash(t_list **stash)
{
	t_list *last;
	t_list *new_node;
	char *clean_content;
	int i;

	last = ft_lstlast(*stash);
	i = 0;
	if (ft_strchr(last->content, '\n'))
		clean_content = ft_strdup(ft_strchr(last->content, '\n') + 1);
	else
		clean_content = ft_strdup(last->content);
	new_node = ft_lstnew(clean_content);
	free_stash(*stash); 
	*stash = new_node;
}
