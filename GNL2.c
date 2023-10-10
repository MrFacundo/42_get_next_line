#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#ifndef BUFFER_SIZE
 #define BUFFER_SIZE 5
#endif

int	gnl_strlen(char *str)
{
	int i = 0;
	if (!str)
		return 0;
	while (str[i])
		if (str[i++] == '\n')
			break ;
	return i;
}

char *join_line_and_buffer(char *line, char *buffer)
{
	int line_len = gnl_strlen(line) + gnl_strlen(buffer) + 1;
	char *ret = malloc(line_len);
	char *temp = ret;
	int i = 0;

	if (line)
	{
		while (line[i])
			*temp++ = line[i++];
		free(line);
	}
	while (*buffer)
	{
		*temp++ = *buffer;
		if (*buffer++ == '\n')
			break;
	}
	*temp = 0;
	return ret;
}

int check_and_clear_buffer(char *buffer)
{
	int i = 0;
	int j = 0;
	int has_nl = 0;

	while (buffer[i])
	{
		if (has_nl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			has_nl = 1;
		buffer[i++] = 0;
	}
	return has_nl;
}

char *get_next_line(int fd)
{
	static char buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char *line = 0;

	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE))
	{
		line = join_line_and_buffer(line, buffer[fd]);
		if (check_and_clear_buffer(buffer[fd]))
			break;
	}
	return line;
}

int	main()
{
	int fd = open("tests/lines_around_10.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s",  line);
		line = get_next_line(fd);
	}
	return 0;
}
