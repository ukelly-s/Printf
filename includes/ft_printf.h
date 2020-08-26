#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <float.h>
# include "../libft/libft.h"

# define RED "\033[1;31m"
# define BLUE "\033[0;34m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

enum				e_ptf_sizes
{
	SHORT = (1 << 6),
	LONG = (1 << 7),
	LLONG = (1 << 8),
	INTMAX = (1 << 9),
	CHAR = (1 << 10),
	LDBL = (1 << 11),
	PTR = INTMAX
};

enum				e_ptf_flags
{
	FLAG_MINUS = (1 << 0),
	FLAG_PLUS = (1 << 1),
	FLAG_SPACE = (1 << 2),
	FLAG_OCTOTHORPE = (1 << 3),
	FLAG_REDUCE = (1 << 4),
	FLAG_ZPADD = (1 << 5),
	FLAG_PTR = PTR | FLAG_OCTOTHORPE,
	BUFF_SIZE = 512,
	BIG_INT = (sizeof(long long) * 8 + 2)
};

typedef struct		s_ptf_float
{
	char			*num;
	int				sgn;
	long double		ld;
	char			*res;
}					t_ptf_float;

typedef struct		s_ptf_all
{
	va_list			arg;
	char			buff[BUFF_SIZE + 1];
	size_t			buff_index;
	int				cap;
	int				fd;
	int				flags;
	const char		*frmt;
	int				prec;
	size_t			printed;
	void			(*release)(struct s_ptf_all*);
	int				width;
}					t_ptf_all;

int					ft_printf(const char *format, ...);
int					pars(register t_ptf_all *info);
void				ft_format(t_ptf_all*info);
void				ft_find_size(t_ptf_all *info);
void				ft_type(t_ptf_all *info);
void				width_prec(t_ptf_all *info);
void				ft_padd(t_ptf_all *info, int len_padd, const char padd);
void				print_all(t_ptf_all *info, char *data, size_t size);
void				ft_print_fl(t_ptf_all *info);
void				ft_float(t_ptf_all *info);
void				ft_str_arg(t_ptf_all *info);
void				ft_chr_arg(t_ptf_all *info);
void				ft_pt_str(t_ptf_all *info, char *str, size_t size);
void				ft_nmbr_arg(t_ptf_all *info);
void				ft_unmbr_arg(t_ptf_all *info, int base);
int					get_pref(t_ptf_all *info, const int radix, const int len,
					char symbol);
int					pref_add(t_ptf_all *info, char *str, int symbol, int radix);
void				choose_colors(t_ptf_all *info);

#endif
