# include <fcntl.h> // open
# include <stdio.h> // FOPEN, printf
# include <stdlib.h> // malloc
# include <unistd.h> // read

# define BUFFER_SIZE 5



int gnl_strlen(char	*string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		i++;
	return (i);
}

char	*join_line_and_buffer(char *line, char *buffer)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(gnl_strlen(line) + gnl_strlen(buffer) + 1);
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
		new_str[i++] = *buffer;
		if (*buffer == '\n')
			break;
		buffer++;
	}
	new_str[i] = 0;
	return (new_str);
}

int	reset_buffer(char *buffer)
{
	int	has_nl;
	int	i;
	int	j;

	i = 0;
	j = 0;
	has_nl	= 0;

	while (buffer[i])
	{
		if (has_nl)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			has_nl = 1;
		buffer[i++] = '\0';
	}
	return (has_nl);
}

char	*gnl(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = 0;
	i = 0;
	if(fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		while (buffer[fd][i])
			buffer[fd][i++] = 0;
		return (0);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line = join_line_and_buffer(line, buffer[fd]);
		if (reset_buffer(buffer[fd]))
			break;
	}
	return line;
}

int	main()
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;


	fd1 = open("./tests/lines_around_10.txt", O_RDONLY);
	fd2 = open("./tests/1char.txt", O_RDONLY);
	fd3 = open("./tests/one_line_no_nl.txt", O_RDONLY);
	fd4 = open("./tests/only_nl.txt", O_RDONLY);

	printf("line 1 %s", gnl(fd1));
	printf("line 2 %s", gnl(fd4));
	printf("line 3 %s", gnl(fd2));
	printf("line 4 %s", gnl(fd4));
	printf("line 5 %s", gnl(fd3));
	printf("line 6 %s", gnl(fd4));
	printf("line 7 %s", gnl(fd4));
	printf("line 8 %s", gnl(fd4));

	// close(fd);
	return (0);
}