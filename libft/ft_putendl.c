#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s == NULL)
		return ;
	ft_putstr(s);
	write(1, "\n", 1);
}
