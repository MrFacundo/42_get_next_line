#include "../include/get_next_line.h"
#include <fcntl.h> // open
#include <stdio.h> // printf, to remove later

int main()
{
	int	fd;
	char *line;

	fd = open("tests/test_file", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}