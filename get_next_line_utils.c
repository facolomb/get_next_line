/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:13:44 by facolomb          #+#    #+#             */
/*   Updated: 2021/12/16 11:13:44 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	x;

	x = 0;
	while (c[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		str_len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(str_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			str_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	i = 0;
	str_len = 0;
	if (str == NULL)
		return (NULL);
	while (i < start)
	{
		i++;
	}
	while (str_len < len && start < ft_strlen(s))
	{
		str[str_len] = s[i];
		str_len++;
		i++;
	}
	str[str_len] = '\0';
	return (str);
}
