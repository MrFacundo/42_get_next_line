#include "./get_next_line.h"
#include <fcntl.h> // open

int main()
{
	int	fd;

	char *line;

	fd = open("../tests/lines_around_10.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	close(fd);
	free(line);
	return (0);
}