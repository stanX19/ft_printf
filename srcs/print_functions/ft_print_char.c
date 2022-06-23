#include "ft_printf.h"

void	print_char(format_t format, va_list argv, size_t* len)
{
	if (format.left)
	{
		ft_putchar(va_arg(argv, int), len);
		while (--format.len > 0)
			ft_putchar(' ', len);
		return ;
	}
	while (--format.len > 0)
		ft_putchar(' ', len);
	ft_putchar(va_arg(argv, int), len);
}