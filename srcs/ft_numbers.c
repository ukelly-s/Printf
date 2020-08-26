#include "../includes/ft_printf.h"

void			ft_print_unmbr(t_ptf_all *info, uintmax_t nmbr, int radix)
{
	char		str[BIG_INT];
	size_t		need_print;

	need_print = 0;
	if (info->flags & (LLONG | LONG | INTMAX))
		need_print = ft_ultoa_radix(nmbr, str, radix, info->cap);
	else
		need_print = ft_uitoa_radix(nmbr, str, radix, info->cap);
	if (info->flags & (FLAG_REDUCE | FLAG_MINUS))
		info->flags &= ~FLAG_ZPADD;
	if ((nmbr == 0 && radix != 8 && !(info->flags & PTR))
		|| (nmbr == 0 && radix == 8 && !(info->flags & FLAG_REDUCE)))
		info->flags &= ~FLAG_OCTOTHORPE;
	if (nmbr == 0 && info->flags & FLAG_REDUCE && info->prec == 0)
		need_print = 0;
	info->width -= get_pref(info, radix, need_print, 0);
	print_all(info, str, need_print);
	ft_padd(info, info->width, ' ');
}

static void		chk_width(t_ptf_all *info, uintmax_t unmb, char *str,
				char symbol)
{
	int		radix;

	radix = 10;
	if (unmb == 0 && info->flags & FLAG_REDUCE && info->prec == 0)
	{
		info->width -= get_pref(info, radix, 0, symbol);
		print_all(info, str, 0);
		ft_padd(info, info->width, ' ');
	}
	else
	{
		info->width -= get_pref(info, radix, ft_strlen(str), symbol);
		print_all(info, str, ft_strlen(str));
		ft_padd(info, info->width, ' ');
	}
}

void			ft_nmbr_arg(t_ptf_all *info)
{
	intmax_t		nmb;
	uintmax_t		unmb;
	char			*str;
	char			symbol;

	if (info->flags & CHAR)
		nmb = (char)va_arg(info->arg, int);
	else if (info->flags & SHORT)
		nmb = (short)va_arg(info->arg, int);
	else if (info->flags & LONG)
		nmb = va_arg(info->arg, long);
	else if (info->flags & LLONG)
		nmb = va_arg(info->arg, long long);
	else
		nmb = va_arg(info->arg, int);
	symbol = (char)(nmb < 0);
	unmb = (nmb < 0) ? -nmb : nmb;
	if (!(info->flags & FLAG_REDUCE))
		info->prec = 0;
	str = ft_ltoa(unmb);
	if (info->flags & (FLAG_REDUCE | FLAG_MINUS))
		info->flags &= ~FLAG_ZPADD;
	chk_width(info, unmb, str, symbol);
	free(str);
}

void			ft_unmbr_arg(t_ptf_all *info, int radix)
{
	uintmax_t nmbr;

	if (info->flags & CHAR)
		nmbr = (unsigned char)va_arg(info->arg, unsigned int);
	else if (info->flags & SHORT)
		nmbr = (unsigned short)va_arg(info->arg, unsigned int);
	else if (info->flags & LONG)
		nmbr = va_arg(info->arg, unsigned long);
	else if (info->flags & LLONG)
		nmbr = va_arg(info->arg, unsigned long long);
	else if (info->flags & INTMAX)
		nmbr = va_arg(info->arg, uintmax_t);
	else
		nmbr = va_arg(info->arg, unsigned int);
	if (!(info->flags & FLAG_REDUCE))
		info->prec = 0;
	ft_print_unmbr(info, nmbr, radix);
}
