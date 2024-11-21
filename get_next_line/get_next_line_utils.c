#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *bucket, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!bucket)
	{
		bucket = (char *)malloc(1 * sizeof(char));
		bucket[0] = '\0';
	}
	if (!bucket || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(bucket) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (bucket)
		while (bucket[++i] != '\0')
			str[i] = bucket[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(bucket) + ft_strlen(buff)] = '\0';
	free(bucket);
	return (str);
}
