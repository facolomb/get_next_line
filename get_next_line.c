/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:13:34 by facolomb          #+#    #+#             */
/*   Updated: 2021/12/16 11:13:34 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_read_line(int fd, char *buffer, char **str)
{
	int		i;
	char	*temp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		while (i > 0)
		{
			buffer[i] = '\0';
			if (!*str)
				*str = ft_substr(buffer, 0, i);
			else
			{
				temp = *str;
				*str = ft_strjoin(*str, buffer);
				free(temp);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			i = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
}

static char	*ft_process(char **str)
{
	int		i;
	int		j;
	char	*ret;
	char	*temp;

	if (!*str)
		return (0);
	if (!ft_strchr(*str, '\n'))
	{
		ret = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (ret);
	}
	i = ft_strlen(*str);
	j = ft_strlen(ft_strchr(*str, '\n'));
	ret = ft_substr(*str, 0, i - j + 1);
	temp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1, j - 1);
	free(temp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	if (BUFFER_SIZE < 1 || fd == -1 || read(fd, buffer, 0) == -1)
	{
		free(buffer);
		return (0);
	}
	ft_read_line(fd, buffer, &str);
	if (str != NULL && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (ft_process(&str));
}
