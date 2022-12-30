#include "./get_next_line.h"
#include <fcntl.h> // open

int main()
{
	int	fd;
	char *line;

	fd = open("../tests/read_error.txt", O_RDONLY);
	// printf("%s", get_next_line(fd));
	line = get_next_line(fd);
	printf("%s", line);
	fd = -1;
	line = get_next_line(fd);
	printf("%s", line);	
	close(fd);
	fd = open("../tests/read_error.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	return (0);
}