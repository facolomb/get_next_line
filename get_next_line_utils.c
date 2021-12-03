#include "get_next_line.h"
#include <stdio.h>

int	ft_is_new_line(const char *str)
{
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (dstsize > 0)
	{	
		while (i + 1 < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_size);
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
	str = malloc(sizeof(char) * (str_len + 1));
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

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
