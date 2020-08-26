#include "libft.h"

static int	test(int symb, unsigned long long number, const char *str)
{
	if (symb == -1 && number > 9223372036854775807)
		return (0);
	if (symb == 1 && number >= 9223372036854775807)
		return (-1);
	if (symb == -1 && number >= 922337203685477580 && (*str - '0') > 8)
		return (0);
	if (symb == 1 && number >= 922337203685477580 && (*str - '0') > 7)
		return (-1);
	if (symb == -1 && (number >= 9223372036854775800 &&
		number < 9223372036854775807) && (*str - '0') >= 0)
		return (0);
	if (symb == 1 && (number >= 9223372036854775800 &&
		number <= 9223372036854775807) && (*str - '0') >= 0)
		return (-1);
	return (1);
}

int			ft_atoi(const char *str)
{
	int					symb;
	unsigned long long	number;

	number = 0;
	symb = 1;
	while (*str == '\n' || *str == '\t' || *str == ' '
		|| *str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			symb *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (test(symb, number, str) == 0)
			return (0);
		else if (test(symb, number, str) == -1)
			return (-1);
		number = number * 10 + *str - '0';
		str++;
	}
	return (symb * number);
}
