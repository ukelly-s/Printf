#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;

	len = ft_strnlen(dst, size);
	if (size == len)
		return (size + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, size - len));
}
