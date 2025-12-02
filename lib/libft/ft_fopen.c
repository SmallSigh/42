/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_filename_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:39:32 by masmit            #+#    #+#             */
/*   Updated: 2025/05/16 18:34:58 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_flags(const char *mode, int *flags)
{
	if (ft_strcmp(mode, "r") == 0)
		*flags = O_RDONLY;
	else if (ft_strcmp(mode, "r+") == 0)
		*flags = O_RDWR;
	else if (ft_strcmp(mode, "w") == 0)
		*flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (ft_strcmp(mode, "w+") == 0)
		*flags = O_RDWR | O_CREAT | O_TRUNC;
	else if (ft_strcmp(mode, "a") == 0)
		*flags = O_WRONLY | O_CREAT | O_APPEND;
	else if (ft_strcmp(mode, "a+") == 0)
		*flags = O_RDWR | O_CREAT | O_APPEND;
	else
		return (1);
	return (0);
}

t_file	*ft_fopen(const char *filename, const char *mode)
{
	t_file	*file;
	int		flags;
	int		fd;

	if (set_flags(mode, &flags) == 1)
		return (NULL);
	fd = open(filename, flags, 0644);
	if (fd == -1)
		return (perror(NO_OPEN), NULL);
	file = malloc(sizeof(t_file));
	if (!file)
		return (close(fd), perror(MEM_FAIL), NULL);
	ft_bzero(file, sizeof(t_file));
	file->buffer = malloc(4096);
	if (!file->buffer)
		return (close(fd), free(file), perror(MEM_FAIL), NULL);
	file->fd = fd;
	file->buf_size = 4096;
	return (file);
}

int	ft_fclose(t_file *file)
{
	int	result;

	if (file == NULL)
		return (-1);
	result = close(file->fd);
	free(file->buffer);
	free(file);
	return (result);
}
