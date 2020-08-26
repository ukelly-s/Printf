#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*sorc;

	if ((unsigned char*)dst == NULL && (unsigned char*)src == NULL)
		return (NULL);
	dest = (unsigned char*)dst;
	sorc = (unsigned char*)src;
	while (n--)
	{
		*dest = *sorc;
		if (*sorc == (unsigned char)c)
			return (++dest);
		dest++;
		sorc++;
	}
	return (NULL);
}
