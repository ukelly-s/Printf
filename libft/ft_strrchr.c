#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s1;

	len = ft_strlen(s);
	s1 = (char*)s + len;
	while (len + 1)
	{
		if ((char)c == *s1)
			return (s1);
		if (*s1 == '\0' && (char)c == '\0')
			return (s1);
		s1--;
		len--;
	}
	return (NULL);
}
