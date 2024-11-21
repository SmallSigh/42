#include "get_next_line.h"

char *empty_bucket(char *bucket)
{
	int i;
	int j;
	char *new_bucket;

	i = 0;
	j = 0;
	while (bucket[i] && bucket[i] != '\n')
		i++;
	if (!bucket[i])
	{
		free(bucket);
		return (NULL);
	}
	new_bucket = malloc(sizeof(char) * (ft_strlen(bucket) - i));
	if (!new_bucket)
		return (NULL);
	i++;
	while (bucket[i])
		new_bucket[j++] = bucket[i++];
	new_bucket[j] = '\0';
	free(bucket);
	return (new_bucket); 
}

char *fill_aquarium(char *bucket)
{
	char *aquarium;
	int i;

	i = 0;
	if (!bucket[i])
		return (NULL);
	while (bucket[i] && bucket[i] != '\n')
		i++;
	aquarium = (char *)malloc(sizeof(char) * (i + 2));
	if (!aquarium)
		return (NULL);
	i = 0;
	while (bucket[i] && bucket[i] != '\n')
	{
		aquarium[i] = bucket[i];
		i++;
	}
	if (bucket[i] == '\n')
	{
		aquarium[i] = bucket[i];
		i++;
	}
	aquarium[i] = '\0';
	return (aquarium);
}

char	*fill_the_bucket(int fd, char *bucket)
{
	int rd_bytes;
	char *buffer;

	rd_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(bucket, '\n') && (rd_bytes != 0))
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		bucket = ft_strjoin(bucket, buffer);
	}
	free(buffer);
	// buffer = NULL;
	return (bucket);
}

char	*get_next_line(int fd)
{
	char		*aquarium;
	static char	*bucket;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bucket = fill_the_bucket(fd, bucket);
	if (!bucket)
		return (0);
	aquarium = fill_aquarium(bucket);
	bucket = empty_bucket(bucket);
	return (aquarium);
}

int	main(void)
{
    int		fd;
    char	*s;

    fd = open("1.txt", O_RDONLY);
    if (fd == -1)
	{
		perror("Error opening file");
        return (1);
	}
    while ((s = get_next_line(fd)) != NULL)
    {
        printf("%s", s);
        free(s);
    }
	close(fd);
    return (0);
}