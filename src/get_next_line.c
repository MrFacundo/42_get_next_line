/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:37 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/31 13:58:08 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/* while no newlines are found, reads file descriptor into a buffer,
a BUFFER_SIZE amount of bytes, nul terminates bufferfer and adds it to a stash */
void fd_to_stash(int fd, char *buffer, char **stash)
{
	int chars_read;
	char *tmp;

	if (!*stash || !ft_strchr(*stash, '\n'))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		while (chars_read > 0)
		{
			buffer[chars_read] = 0;
			if (!*stash)
				*stash = ft_substr(buffer, 0, chars_read);
			else
			{
				tmp = *stash;
				*stash = ft_strjoin(*stash, buffer);
				free(tmp);
			}
			if (ft_strchr(buffer, '\n'))
				break;
			chars_read = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

/* returns a string containing a line */
char *stash_to_line(char *stash)
{
	int i;
	int j;

	if (!stash || !*stash)
		return (0);
	if (!ft_strchr(stash, '\n'))
		return ft_substr(stash, 0, ft_strlen(stash));
	i = ft_strlen(stash);
	j = ft_strlen(ft_strchr(stash, '\n'));
	return ft_substr(stash, 0, i - j + 1);
}

/* resets stash and frees memory*/
void clear_stash(char **stash)
{
	int j;
	char *tmp;

	if (!ft_strchr(*stash, '\n'))
	{
		free(*stash);
		*stash = 0;
	}
	else
	{
		j = ft_strlen(ft_strchr(*stash, '\n'));
		tmp = *stash;
		*stash = ft_substr(ft_strchr(*stash, '\n'), 1, j - 1);
		free(tmp);
	}
}

/*	1. reads and stashes fd
	2. dumps stash into allocated line
	3. resets stash s and frees memory */
char *get_next_line(int fd)
{
	static char *stash;
	char *buffer;
	char *ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || fd > FD_MAX || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		free(stash);
		stash = 0;
		return (0);
	}
	fd_to_stash(fd, buffer, &stash);
	ret = stash_to_line(stash);
	if (stash)
		clear_stash(&stash);
	return (ret);
}
