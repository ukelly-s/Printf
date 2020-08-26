#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;

	len = ft_strlen(needle);
	if (ft_strlen(haystack) == 0 && len == 0)
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle || len == 0)
			if (ft_strncmp(haystack, needle, len) == 0)
				return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
