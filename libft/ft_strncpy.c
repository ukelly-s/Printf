#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *dest;

	if (ft_strnlen(src, len) != len)
		ft_memset(dst + ft_strnlen(src, len), '\0', len - ft_strnlen(src, len));
	dest = ft_memcpy(dst, src, ft_strnlen(src, len));
	return (dest);
}
