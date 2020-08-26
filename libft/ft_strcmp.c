
#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1_b;
	unsigned char *s2_b;

	s1_b = (unsigned char*)s1;
	s2_b = (unsigned char*)s2;
	while (*s1_b == *s2_b)
	{
		if (*s1_b == '\0' && *s2_b == '\0')
			return (0);
		s1_b++;
		s2_b++;
	}
	return (*s1_b - *s2_b);
}
