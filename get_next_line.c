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
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_fill_line(char *line, char *readed)
{
	if (!line)
		line = ft_strdup(readed);
	else
		line = ft_strjoin(line, readed);
	return (line);
}

char	*get_next_line(int fd)
{
    char	readed[BUFFER_SIZE + 1];
	char	*line;
	int		nb_bytes;

	nb_bytes = 1;
	line = NULL;
	while (ft_is_new_line(line) == 0 && nb_bytes > 0)
	{
		nb_bytes = read(fd, readed, BUFFER_SIZE);
		if (nb_bytes <= 0 && !line)
			return (NULL);
		if (nb_bytes == 0 && line != NULL)
			return (line);
		readed[nb_bytes] = '\0';
		line = ft_fill_line(line, readed);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("open failed");
		return (0);
	}
	while (i <= 2)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close(fd);
	return (0);
}
*/