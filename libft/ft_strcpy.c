#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *dest;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = dst;
	while ((*dst++ = *src++) != '\0')
		;
	return (dest);
}
