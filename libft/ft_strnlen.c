#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t len;

	len = 0;
	while (*s++)
		len++;
	if (len >= maxlen)
		return (maxlen);
	else
		return (len);
}
