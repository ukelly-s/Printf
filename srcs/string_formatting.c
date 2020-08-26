#include "../includes/ft_printf.h"

void	ft_pt_str(t_ptf_all *info, char *str, size_t size)
{
	size_t	need_print;
	char	padd;

	padd = (info->flags & FLAG_ZPADD && !(info->flags & FLAG_MINUS))
			? '0' : ' ';
	if (info->flags & FLAG_REDUCE)
		need_print = (info->prec < (long int)size) ? info->prec : size;
	else
		need_print = size;
	if (info->width > 0 && (info->width -= need_print) > 0)
	{
		info->flags &= ~FLAG_ZPADD;
		if (info->flags & FLAG_MINUS)
		{
			print_all(info, str, need_print);
			ft_padd(info, info->width, padd);
		}
		else
		{
			ft_padd(info, info->width, padd);
			print_all(info, str, need_print);
		}
	}
	else
		print_all(info, str, need_print);
}

void	ft_str_arg(t_ptf_all *info)
{
	char	*str;

	if (!(str = va_arg(info->arg, char*)))
		ft_pt_str(info, "(null)", 6);
	else
		ft_pt_str(info, str, ft_strlen(str));
}

void	ft_chr_arg(t_ptf_all *info)
{
	char	symbol;

	symbol = '\0';
	if (info->prec == 0)
		info->prec = 1;
	symbol = (char)va_arg(info->arg, int);
	ft_pt_str(info, &symbol, 1);
}
