#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*str;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if ((len_s - (size_t)start) < len)
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
