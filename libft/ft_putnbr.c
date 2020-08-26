#include "libft.h"

void	ft_putnbr(int n)
{
	long int numb;
	long int count;
	long int num;

	numb = n;
	if (numb < 0)
	{
		write(1, "-", 1);
		numb *= -1;
	}
	num = numb;
	count = 1;
	while ((num /= 10) > 0)
		count *= 10;
	while (count)
	{
		num = numb / count;
		ft_putchar(num + '0');
		numb -= num * count;
		count /= 10;
	}
}
