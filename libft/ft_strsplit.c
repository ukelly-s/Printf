#include "libft.h"

static size_t	strin(const char *s, char c)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			len++;
			break ;
		}
		if (*s != c)
			len++;
		s++;
	}
	return (len);
}

static size_t	strilen(char const *s, char c)
{
	size_t len;

	len = 0;
	if (!s || *s == '\0')
		return (0);
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			len++;
		s++;
	}
	return (len);
}

static char		**free_arr(char **src)
{
	while (*src)
	{
		free(*src);
		src++;
	}
	free(src);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	**src;
	size_t	len;

	if (!s || !(str = (char**)malloc(sizeof(char*) * strilen(s, c) + 1)))
		return (NULL);
	src = str;
	while (*s)
	{
		if (*s != c && *s != '\0')
		{
			len = strin(s, c);
			if ((*str = ft_strnew(len)) == NULL)
				return (free_arr(src));
			ft_memcpy(*str, s, len);
			s += len - 1;
			str++;
		}
		s++;
	}
	*str = NULL;
	return (src);
}
