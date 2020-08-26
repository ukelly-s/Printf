#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int numb;
	long int count;
	long int num;

	numb = n;
	if (numb < 0)
	{
		write(fd, "-", 1);
		numb *= -1;
	}
	num = numb;
	count = 1;
	while ((num /= 10) > 0)
		count *= 10;
	while (count)
	{
		num = numb / count;
		ft_putchar_fd(num + '0', fd);
		numb -= num * count;
		count /= 10;
	}
}
