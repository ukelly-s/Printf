#include "libft.h"

static size_t	ft_lensp(char const *src)
{
	size_t len;
	size_t i;

	if (*src == '\0')
		return (0);
	len = ft_strlen(src) - 1;
	i = 0;
	while (src[len] == ' ' || src[len] == '\n' || src[len] == '\t')
	{
		i++;
		len--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;

	str = NULL;
	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s) - ft_lensp(s);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
