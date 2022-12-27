#include <fcntl.h>

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