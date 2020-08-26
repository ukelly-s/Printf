#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size + 1 == 0)
		return (NULL);
	str = (char*)malloc(size * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	return (ft_memset(str, '\0', size + 1));
}
