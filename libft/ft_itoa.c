#include "libft.h"

static size_t	str_len(long int numb)
{
	size_t len;

	len = 0;
	if (numb <= 0)
	{
		numb *= -1;
		len++;
	}
	while (numb != 0)
	{
		len++;
		numb /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	numb;
	char		*src;

	numb = n;
	len = str_len(numb);
	if (!(str = ft_strnew(len)))
		return (NULL);
	src = str;
	if (numb <= 0)
	{
		*str = (numb < 0) ? (45) : (48);
		numb *= -1;
	}
	str += len;
	while (numb)
	{
		*(--str) = (numb % 10) + '0';
		numb /= 10;
	}
	return (src);
}
