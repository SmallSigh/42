/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:39:32 by masmit            #+#    #+#             */
/*   Updated: 2024/10/15 15:28:55 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int	main(void)
{
	t_file	*file;
	int		c;

	file = ft_fopen("text", "r");
	if (file == NULL)
		return (perror(NO_OPEN), 1);
	write(1, "file opened succesfully!\n", 26);
	while ((c = ft_fgetc(file)) != -1)
		write(1, &c, 1);
	ft_fclose(file);
	return (0);
}
