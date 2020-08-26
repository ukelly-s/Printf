#include "../includes/ft_printf.h"

int		pref_add(t_ptf_all *info, char *str, int symbol, int radix)
{
	int		res;

	res = 0;
	str[0] = 0;
	if (symbol)
		str[res++] = '-';
	else if (info->flags & (FLAG_PLUS | FLAG_SPACE))
		str[res++] = " +"[(info->flags & FLAG_PLUS) != 0];
	if ((radix != 10 && info->flags & FLAG_OCTOTHORPE))
	{
		str[res++] = '0';
		if (radix == 16)
			str[res++] = "xX"[info->cap];
	}
	return (res);
}

int		get_pref(t_ptf_all *info, const int radix, const int len,
		char symbol)
{
	char	pref[3];
	int		len_pref;
	int		len_z;
	int		len_padd;

	len_pref = pref_add(info, pref, symbol, radix);
	if (info->flags & FLAG_ZPADD)
		len_z = info->width - len_pref - len;
	else
		len_z = info->prec - len - (radix == 8 && pref[0] == '0');
	len_z = (len_z < 0) ? 0 : len_z;
	len_padd = 0;
	if (!(info->flags & FLAG_MINUS))
	{
		len_padd = info->width - len_z - len - len_pref;
		ft_padd(info, len_padd, ' ');
		print_all(info, pref, len_pref);
		ft_padd(info, len_z, '0');
	}
	else
	{
		print_all(info, pref, len_pref);
		ft_padd(info, len_z, '0');
	}
	return (len_padd + len + len_z + len_pref);
}

void	ft_padd(t_ptf_all *info, int len_padd, const char padd)
{
	char		*padd_now;
	const char	padd_zero[] = "00000000";
	const char	padd_space[] = "        ";

	if (len_padd > 0)
	{
		padd_now = (char*)((padd == '0') ? padd_zero : padd_space);
		while (len_padd >= 8)
		{
			print_all(info, padd_now, 8);
			len_padd -= 8;
		}
		while (len_padd >= 4)
		{
			print_all(info, padd_now, 4);
			len_padd -= 4;
		}
		while (len_padd--)
			print_all(info, padd_now, 1);
	}
}

void	print_color(t_ptf_all *info)
{
	const char *c = info->frmt;

	if (*c == 'R')
		write(info->fd, RED, 7);
	else if (*c == 'G')
		write(info->fd, GREEN, 7);
	else if (*c == 'B')
		write(info->fd, BLUE, 7);
	else if (*c == 'E')
		write(info->fd, RESET, 7);
}

void	choose_colors(t_ptf_all *info)
{
	info->frmt++;
	if (*info->frmt)
	{
		if (*info->frmt == 'R' || *info->frmt == 'G' || *info->frmt == 'B'
			|| *info->frmt == 'E')
		{
			if (*(info->frmt + 1) == '}')
			{
				print_color(info);
				info->frmt++;
			}
		}
	}
}
