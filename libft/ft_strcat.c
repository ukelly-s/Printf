#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *src;

	src = s1;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (src);
}
