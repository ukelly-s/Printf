#include "./libft.h"

size_t	ft_ultoa_radix(uint64_t nmbr, char *buff, const int radix,
		const int upper)
{
	const char	value[] = "0123456789abcdef0123456789ABCDEF";
	char		*ptr;
	size_t		output;

	ptr = buff;
	*ptr++ = value[(nmbr % radix) + (upper != 0) * 16];
	nmbr /= radix;
	while (nmbr != 0)
	{
		*ptr++ = value[(nmbr % radix) + (upper != 0) * 16];
		nmbr /= radix;
	}
	ft_strrev(buff, ptr - 1);
	output = ptr - buff;
	if (radix == 16)
		buff[output + 1] = 0;
	else
		buff[output] = 0;
	return (output);
}
