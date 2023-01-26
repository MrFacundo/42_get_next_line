#include "./get_next_line.h"

int		gnl_strlen(char	*buffer)
{
	int i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (i);
}

char	*join_line_and_buffer(char	*line, char	*buffer)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = 	malloc(gnl_strlen(line) + gnl_strlen(buffer) + 1);
	if (!new_str)
		return (0);	
	while (line && line[i])
	{
		new_str[i] = line[i];
		i++;
	}
	free(line);
	while (buffer && *buffer)
	{
		new_str[i] = *buffer;
		i++;
		if (*buffer == '\n')
			break ;
		buffer++;
	}
	new_str[i] = '\0';
	return new_str;
}

int	reset_buffer(char *buffer)
{
	int	has_nl;
	int	i;
	int	j;

	has_nl = 0;
	i =	0;
	j = 0;
	while(buffer[i])
	{
		if (has_nl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			has_nl = 1;
		buffer[i] = '\0';
		i++;
	}
	return has_nl;
}

char	*gnl_short(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int i;
	char	*line;

	i = 0;
	if(fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		while (buffer[fd][i])
			buffer[fd][i++] = 0;
		return (0);
	}
	line = 0;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = join_line_and_buffer(line, buffer[fd]);
		if (reset_buffer(buffer[fd]))
			break;
	}
	return line;
}