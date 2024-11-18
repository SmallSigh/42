#include "get_next_line.h"

char *buffer_to_line(int fd, char *buffer, char *bucket)
{
    int read_bytes;
    char *char_temp;

	read_bytes = 1;
	while (read_bytes != '\0')
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (0);
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!bucket)
			bucket = ft_strdup("");
		char_temp = bucket;
		bucket = ft_strjoin(char_temp, buffer);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (bucket);
}

char *get_next_line(fd)
{
    char *buffer;
    char *line;
    static char *bucket;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE * 1));
    if (!buffer)
        return (0);
    line = buffer_to_line(fd, buffer, bucket);
    free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	bucket = extract(line);
    return (line);
}

int main(void)
{
    int fd;
    char *s;

    fd = open("/txt.1", O_RDONLY);
    if (fd == -1)
        return (1);
    while (*s = get_next_line(fd) != NULL)
    {
        printf("%s", s);
        free(s);
    }
    return (0);
}