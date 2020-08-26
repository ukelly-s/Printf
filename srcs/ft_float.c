#include "../includes/ft_printf.h"

static int				get_pref_fl(t_ptf_all *info, const int radix, int w_len,
						char symbol)
{
	char	pref[3];
	int		len_p;
	int		padd;

	len_p = pref_add(info, pref, symbol, radix);
	padd = (info->flags & FLAG_ZPADD && !(info->flags & FLAG_MINUS))
		? '0' : ' ';
	if (info->width - (w_len + len_p) > 0 && !(info->flags & FLAG_MINUS))
		if (info->flags & FLAG_ZPADD)
		{
			print_all(info, pref, len_p);
			ft_padd(info, info->width - (w_len + len_p), padd);
			len_p += info->width - (w_len + len_p);
		}
		else
		{
			ft_padd(info, info->width - (w_len + len_p), padd);
			print_all(info, pref, len_p);
			len_p += info->width - (w_len + len_p);
		}
	else
		print_all(info, pref, len_p);
	return (w_len + len_p);
}

static long double		chk_size(t_ptf_all *info)
{
	double			fl;
	long double		lfl;

	fl = 0.0;
	lfl = 0.0;
	if (info->flags & LDBL)
	{
		lfl = va_arg(info->arg, long double);
		return (lfl);
	}
	else
	{
		fl = va_arg(info->arg, double);
		return (fl);
	}
}

static void				ft_float_help(int *acc, long double *fl,
						long *i, int *sgn)
{
	*fl = (*fl < 0) ? -(*fl) : *fl;
	*i = 0;
	while (*i < *acc)
	{
		(*fl) = (*fl) * 10;
		(*i)++;
	}
	*fl += 0.5;
	while (*i)
	{
		(*i)--;
		*fl /= 10;
	}
	*i = (*acc > 0) ? 1 : 0;
	*i += (*sgn == 1) ? 1 : 0;
}

static void				ft_float1(t_ptf_all *info, t_ptf_float strfloat,
						char *to_free, long i)
{
	if (strfloat.res[i] != '\0')
		strfloat.res[++i] = '\0';
	info->width -= get_pref_fl(info, 10, ft_strlen(strfloat.res),
			strfloat.sgn);
	print_all(info, strfloat.res, i);
	free(strfloat.res);
	free(to_free);
	ft_padd(info, info->width, ' ');
}

void					ft_float(t_ptf_all *info)
{
	t_ptf_float			strfloat;
	long				i;
	long double			fl;
	char				*to_free;

	ft_bzero(&strfloat, sizeof(t_ptf_float));
	fl = chk_size(info);
	strfloat.sgn = ((*(__int128_t*)&fl) >> 79) & 1;
	ft_float_help(&(info->prec), &fl, &i, &(strfloat.sgn));
	strfloat.ld = fl;
	while (strfloat.ld > 1 && ++i)
		strfloat.ld = strfloat.ld / 10;
	strfloat.res = (char*)malloc(sizeof(char) * (i + info->prec + 2));
	i = 0;
	strfloat.num = ft_ltoa((long)fl);
	to_free = strfloat.num;
	while (*(strfloat.num) != '\0')
		strfloat.res[i++] = *(strfloat.num)++;
	strfloat.res[i] = ((info->prec != 0) || (info->prec == 0
			&& info->flags & FLAG_OCTOTHORPE) ? '.' : '\0');
	while (info->prec-- > 0 && (fl = fl * 10) >= 0 && ++i)
		if ((strfloat.res[i] = ((unsigned long long)fl % 10 + '0')))
			fl = fl - (unsigned long long)fl;
	ft_float1(info, strfloat, to_free, i);
}
