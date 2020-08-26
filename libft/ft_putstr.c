#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(1, *&s, 1);
		s++;
	}
}
