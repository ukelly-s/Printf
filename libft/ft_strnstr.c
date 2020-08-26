#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t size;

	size = ft_strlen(needle);
	if ((len == 0 && size == 0) || (ft_strlen(haystack) == 0 && size == 0))
		return ((char*)haystack);
	if ((len != 0 || size != 0) && *haystack != 0)
	{
		while (len--)
		{
			if (size <= len + 1 && ft_strncmp(haystack, needle, size) == 0)
				return ((char*)haystack);
			if (*haystack == '\0')
				return (NULL);
			haystack++;
		}
	}
	return (NULL);
}
