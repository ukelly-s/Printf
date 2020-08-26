#include "../includes/ft_printf.h"

void			ft_format(t_ptf_all *info)
{
	info->flags = 0;
	info->width = 0;
	info->prec = 6;
	info->cap = 0;
	while (*info->frmt)
	{
		if (*info->frmt == '-')
			info->flags |= FLAG_MINUS;
		else if (*info->frmt == '+')
			info->flags |= FLAG_PLUS;
		else if (*info->frmt == '#')
			info->flags |= FLAG_OCTOTHORPE;
		else if (*info->frmt == '0')
			info->flags |= FLAG_ZPADD;
		else if (*info->frmt == ' ')
			info->flags |= FLAG_SPACE;
		else
			break ;
		info->frmt++;
	}
	width_prec(info);
	ft_find_size(info);
	ft_type(info);
}

void			ft_find_size(t_ptf_all *info)
{
	while (*info->frmt)
	{
		if (*info->frmt == 'h')
			info->flags |= (*(info->frmt + 1) == 'h' && ++info->frmt)
					? CHAR : SHORT;
		else if (*info->frmt == 'l')
			info->flags |= (*(info->frmt + 1) == 'l' && ++info->frmt)
					? LLONG : LONG;
		else if (*info->frmt == 'L')
			info->flags |= LDBL;
		else
			break ;
		++info->frmt;
	}
}

static void		else_type(t_ptf_all *info)
{
	if (*info->frmt == '{')
		choose_colors(info);
	else
		print_all(info, (char*)info->frmt, 1);
	info->frmt++;
	ft_type(info);
}

void			ft_type(t_ptf_all *info)
{
	info->cap = ft_strany("FX", *info->frmt);
	if (*info->frmt == 's')
		ft_str_arg(info);
	else if (*info->frmt == 'c')
		ft_chr_arg(info);
	else if (*info->frmt == 'd' || *info->frmt == 'D' || *info->frmt == 'i')
		ft_nmbr_arg(info);
	else if (*info->frmt == 'f')
		ft_float(info);
	else if (*info->frmt == 'p' && (info->flags |= FLAG_PTR))
		ft_unmbr_arg(info, 16);
	else if (*info->frmt == 'o')
		ft_unmbr_arg(info, 8);
	else if (*info->frmt == 'u')
		ft_unmbr_arg(info, 10);
	else if (*info->frmt == 'x' || *info->frmt == 'X')
		ft_unmbr_arg(info, 16);
	else if (*info->frmt == '%')
	{
		if (info->flags & FLAG_REDUCE && info->prec == 0)
			info->prec = 1;
		ft_pt_str(info, "%", 1);
	}
	else
		else_type(info);
}

void			width_prec(t_ptf_all *info)
{
	if (*info->frmt >= '0' && *info->frmt <= '9')
		while (*info->frmt >= '0' && *info->frmt <= '9')
			info->width = 10 * info->width + (*info->frmt++ - '0');
	else if (*info->frmt == '*' && info->frmt++)
	{
		info->width = va_arg(info->arg, int);
		if (info->width < 0 && (info->width = -info->width))
			info->flags |= FLAG_MINUS;
	}
	if (*info->frmt == '.' && info->frmt++)
	{
		info->prec = 0;
		info->flags |= FLAG_REDUCE;
		if (*info->frmt >= '0' && *info->frmt <= '9')
			while (*info->frmt >= '0' && *info->frmt <= '9')
				info->prec = 10 * info->prec + (*info->frmt++ - '0');
		else if (*info->frmt == '*')
		{
			info->prec = va_arg(info->arg, int);
			if (info->prec < 0)
				info->flags &= ~FLAG_REDUCE;
			info->prec = (info->prec < 0) ? 6 : info->prec;
			++info->frmt;
		}
	}
}
