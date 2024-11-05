#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[OPEN_MAX][BUFFER_SIZE + 1];
    char *line;
    int bytesToRead;

if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
line = NULL;

    if (buffer[fd][0] != '\0')
        line = ft_strjoin(line, buffer[fd], ft_strlen(line), ft_strlen(buffer[fd]));

    while (ft_breakline_exists(line)==-1)
    {
        bytesToRead = read(fd,buffer[fd],BUFFER_SIZE);
        buffer[fd][bytesToRead] = '\0';
        if(bytesToRead == 0)
            return (line);
        if(bytesToRead < 0)
            return (NULL);
        line = ft_strjoin(line, buffer[fd], ft_strlen(line), ft_strlen(buffer[fd]));
    }

    return(ft_cut_line(line, buffer[fd]));
}

int main(void)
{
	int fd = open("hello.txt", 0);
	int fd1 = open("text.txt", 0);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd));
	return (0);
}