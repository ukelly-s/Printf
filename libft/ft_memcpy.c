#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const void				*ret = dst;
	register unsigned char	*dest;
	register unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (dest == NULL && source == NULL)
		return (NULL);
	while (n >= 8)
	{
		*((uint64_t*)dest) = *((uint64_t*)source);
		dest += 8;
		source += 8;
		n -= 8;
	}
	while (n >= 4)
	{
		*((uint32_t*)dest) = *((uint32_t*)source);
		dest += 4;
		source += 4;
		n -= 4;
	}
	while (n--)
		*dest++ = *source++;
	return ((void*)ret);
}
