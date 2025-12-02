/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:59:38 by masmit            #+#    #+#             */
/*   Updated: 2024/11/01 17:19:29 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fill_buffer(t_file *file)
{
	int	bytes_read;

	bytes_read = read(file->fd, file->buffer, file->buf_size);
	if (bytes_read <= 0)
	{
		if (bytes_read == 0)
			file->eof = 1;
		else
			file->error = 1;
		return (bytes_read);
	}
	file->buf_pos = 0;
	file->buf_end = bytes_read;
	return (bytes_read);
}

int	ft_fgetc(t_file *file)
{
	if (file == NULL || file->error)
		return (-1);
	if (file->buf_pos >= file->buf_end)
	{
		if (fill_buffer(file) <= 0)
			return (-1);
	}
	return ((unsigned char)file->buffer[file->buf_pos++]);
}
