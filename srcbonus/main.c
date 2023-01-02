#include "./get_next_line_bonus.h"
#include <fcntl.h> // open

int main()
{
	int	fd;

	char *line;

	fd = open("../tests/only_nl.txt", O_RDONLY);

	// printf("%s", get_next_line(fd));
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	// close(fd);
	// line = get_next_line(-1);
	// printf("%s", line);
	// fd = open("../tests/read_error.txt", O_RDONLY);
	// line = get_next_line(fd);
	// printf("%s", line);

	// line = get_next_line(100);
	// printf("%s", line);	
	// line = get_next_line(fd);
	// printf("%s", line);	
	// while (line)
	// {
	// }
	close(fd);
	// fd = open("../tests/read_error.txt", O_RDONLY);
	// line = get_next_line(fd);
	// printf("%s", line);
	free(line);
	return (0);
}