/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facu <facu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:00:39 by ftroiter          #+#    #+#             */
/*   Updated: 2023/01/01 21:22:25 by facu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*buffer;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		len = 0;
		start = 0;
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (0);
	ft_strlcpy(buffer, s + start, len + 1);
	return (buffer);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	buffer = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		buffer[j++] = s1[i++];
	i = 0;
	while (s2[i])
		buffer[j++] = s2[i++];
	buffer[j] = 0;
	return (buffer);
}
