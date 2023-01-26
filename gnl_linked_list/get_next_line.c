/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:37 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/30 20:18:10 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/*	1. reads and stashes fd
	2. dumps stash into allocated line
	3. resets stash so that it begins after the extracted line
	4. frees memory if EOF */
char	*get_next_line(int fd)
{
	char			*line;
	static t_list	*stash = NULL;

	if (fd > FD_MAX || BUFFER_SIZE <= 0)
		return (0);
	if (fd < 0 || read(fd, &line, 0) < 0)
	{
		if (stash)
		{
			free_stash(stash);
			stash = NULL;
		}
		return (0);
	}
	fd_to_stash(fd, &stash);
	if (!stash)
		return (0);
	stash_to_line(&line, stash);
	remove_line_from_stash(&stash);
	if (line[0] == '\0')
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
void	fd_to_stash(int fd, t_list **stash)
{
	char	*buffer;
	int		chars_read;
	t_list	*new_node;

	chars_read = 1;
	while (!newline_in_stash(*stash) && chars_read)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if ((!*stash && !chars_read) || chars_read < 0)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		new_node = ft_lstnew(ft_strdup(buffer));
		ft_lstadd_back(stash, new_node);
		free(buffer);
	}
	return ;
}

/* allocates a line and dumps the stash content into it*/
void	stash_to_line(char **line, t_list *stash)
{
	int	i;
	int	j;

	allocate_line(line, stash);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
	return ;
}

/* resets stash so it begins after the extracted line*/
void	remove_line_from_stash(t_list **stash)
{
	t_list	*last;
	t_list	*new_node;
	char	*clean_content;

	last = ft_lstlast(*stash);
	if (ft_strchr(last->content, '\n'))
		clean_content = ft_strdup(ft_strchr(last->content, '\n') + 1);
	else
		clean_content = ft_strdup(last->content);
	new_node = ft_lstnew(clean_content);
	free_stash(*stash);
	*stash = new_node;
}

char	*newline_in_stash(t_list *stash)
{
	t_list	*last_node;

	if (!stash)
		return (0);
	last_node = ft_lstlast(stash);
	return (ft_strchr(last_node->content, '\n'));
}
