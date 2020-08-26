#include "../includes/ft_printf.h"

void	ft_print_fl(t_ptf_all *info)
{
	write(info->fd, info->buff, info->buff_index);
}

void	print_all(t_ptf_all *info, char *data, size_t size)
{
	int			space;
	size_t		data_index;

	data_index = 0;
	while ((space = BUFF_SIZE - info->buff_index) < (int)size)
	{
		if (size == 1)
			info->buff[info->buff_index] = *(char*)data;
		else
			ft_memcpy(&(info->buff[info->buff_index]), &(data[data_index]),
					space);
		size -= space;
		data_index += space;
		info->buff_index += space;
		info->printed += space;
		info->release(info);
		info->buff_index = 0;
	}
	if (size == 1)
		info->buff[info->buff_index] = ((char*)data)[data_index];
	else
		ft_memcpy(&(info->buff[info->buff_index]), &(data[data_index]), size);
	info->buff_index += size;
	info->printed += size;
}

int		ft_printf(const char *format, ...)
{
	t_ptf_all info;

	ft_bzero(&info, sizeof(t_ptf_all));
	info.fd = 1;
	info.frmt = format;
	if (info.frmt == NULL)
		return (0);
	va_start(info.arg, format);
	info.release = &ft_print_fl;
	return (pars(&info));
}

int		pars(register t_ptf_all *info)
{
	size_t		free_chr;
	char		*start_string;

	while (*info->frmt)
	{
		free_chr = 0;
		start_string = (char*)info->frmt;
		while (*info->frmt && *info->frmt != '%')
		{
			free_chr++;
			info->frmt++;
		}
		print_all(info, start_string, free_chr);
		if (!*info->frmt || !*(++info->frmt))
			break ;
		ft_format(info);
		if (*info->frmt == 0)
			break ;
		info->frmt++;
	}
	info->release(info);
	va_end(info->arg);
	return (info->printed);
}
