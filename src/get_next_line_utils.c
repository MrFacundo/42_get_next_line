/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:39 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/28 20:37:06 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

// Allocates and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL
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

// Adds the node ’new’ at the end of the list.
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
	{
		lst = lst->next;
	}
	return (lst);
}

void get_line_pointer(char **line, t_list *stash)
{
	size_t len;
	len = 0;
	int i;

	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}

	*line = malloc(sizeof(char) * (len + 1));
}

// Allocates and returns a pointer to a  duplicate string of string s.
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

// Returns lenght of string s.
size_t ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

int newline_in_stash(t_list *stash)
{
	int i;
	t_list *last_node;

	if (stash == NULL)
		return (0);
	last_node = ft_lstlast(stash);

	return (ft_strchr(last_node->content, '\n'));
}

// Returns 1 if char c is located in string s, 0 if not.
int ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return (1);
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
