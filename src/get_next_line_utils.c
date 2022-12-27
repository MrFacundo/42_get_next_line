/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:39 by ftroiter          #+#    #+#             */
/*   Updated: 2022/12/27 23:29:44 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

// Allocates and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL
t_list *ft_lstnew(void *content)
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

void get_line_length(char **line, t_list *stash)
{
	size_t len;
	len = 0;

	while (stash)
	{

		while (*stash->content)
		{
			len++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}