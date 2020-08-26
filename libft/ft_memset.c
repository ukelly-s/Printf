#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	if (len == 0)
		return (b);
	while (len--)
		((char *)b)[i++] = (unsigned char)c;
	return (b);
}
