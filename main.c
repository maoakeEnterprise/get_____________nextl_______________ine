
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char	*line;
	int	i;

	fd = open("filetest.txt", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 0;
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
