#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *start;
	unsigned char *finish;

	start = (unsigned char*)dst;
	finish = (unsigned char*)src;
	if (start == NULL && finish == NULL)
		return (NULL);
	if (start <= finish)
	{
		while (len--)
			*start++ = *finish++;
		return (dst);
	}
	else
	{
		while (len--)
			start[len] = finish[len];
		return (dst);
	}
}
