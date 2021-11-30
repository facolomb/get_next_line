/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:17:25 by facolomb          #+#    #+#             */
/*   Updated: 2021/11/30 10:17:25 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#define BUFFER_SIZE

char	*get_next_line(int fd)
{
    char	*readed;
	char	*line;
	int		nb_bytes;

	readed = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readed)
		return (NULL);
	while (!(is_new_line(line)))
	{
		nb_bytes = read(fd, readed, BUFFER_SIZE);
		if (nb_bytes < 0)
			return (NULL);
		readed[nb_bytes] = '\0';
	}
	line = ft_strjoin(line, readed);
	free(readed);
	return (line);
}