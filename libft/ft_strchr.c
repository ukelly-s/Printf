#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*(char*)s != '\0')
	{
		if ((char)c == *(char*)s)
			return ((char*)s);
		s++;
	}
	if (*(char*)s == '\0' && (char)c == '\0')
		return ((char*)s);
	return (NULL);
}
