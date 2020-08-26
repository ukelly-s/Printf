#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *src;

	src = (void*)malloc(size * sizeof(void));
	if (src == NULL)
		return (NULL);
	ft_bzero(src, size);
	return (src);
}
