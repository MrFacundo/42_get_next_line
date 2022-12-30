/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:39 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/30 01:32:12 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*newline_in_stash(t_list *stash)
{
	int i;
	t_list *last_node;
	
	ERROR_CHECK(!stash);
	last_node = ft_lstlast(stash);
	return (ft_strchr(last_node->content, '\n'));
}

void allocate_line(char **line, t_list *stash)
{
	size_t len;
	len = 0;
	int i;

	while (stash)
	{
		if (ft_strchr(stash->content, '\n'))
			len += ft_strlen(stash->content) - ft_strlen(ft_strchr(stash->content, '\n'));
		else
			len += ft_strlen(stash->content);
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_stash(t_list *stash)
{
	t_list	*next;

	while (stash)
	{
		free(stash->content);
		next = stash->next;
		free(stash);
		stash = next;
	}
}

t_list *ft_lstnew(char *content)
{
	t_list *res;
	res = malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = content;
	res->next = NULL;

	return (res);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

char *ft_strdup(const char *s)
{
	char *ptr;
	size_t size;
	size_t i;

	size = ft_strlen(s) + 1;
	ptr = (char *)malloc(sizeof(*s) * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size - 1 && *s)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

size_t ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

