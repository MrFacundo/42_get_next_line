#include "../include/get_next_line.h"
#include <fcntl.h> // open

int main()
{
	int	fd;
	char *line;

	fd = open("../tests/test_file", O_RDONLY);
	// printf("%s", get_next_line(fd));
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}