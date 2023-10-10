#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
 #define BUFFER_SIZE
#endif

int	gnl_strlen(char *str)
{

}


char *join_line_and_buffer(char *line, char *buffer)
{
	int line_len = gnl_strlen(line) + gnl_strlen(line) + 1;
	char *ret = malloc(line_len);
	char *temp = ret;
	int	i = 0;

	if (line)
	{
		while (line[i])
			*temp++ = line[i++];
		free(line);
	}
	while (*buffer)
	{
		*temp++ = *buffer;
		if (*buffer++ == '/n')
			break;
	}
	*temp = 0;
	return temp;
}








char *get_next_line(int fd)
{
	static char buffer[FOPEN_MAX][BUFFER_SIZE];
	char *line = 0;

	while (buffer[fd][0] || read(fd, buffer. BUFFER_SIZE));
	{
		line = join_line_and_buffer(line, buffer);
		if (check_and_clear_buffer(buffer))
			break;
	}
	return line;
}


int	main()
{
	int fd =  open("tests/lines_around_10.txt")
	char *line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return 0;
}