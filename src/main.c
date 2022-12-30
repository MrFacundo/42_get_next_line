#include "../include/get_next_line.h"
#include <fcntl.h> // open

int main()
{
	int	fd;
	char *line;

	fd = open("../tests/test_file", O_RDONLY);
	// printf("%s", get_next_line(fd));
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}