#include "ft_printf.h"

void print_double(format_t format, va_list argv, size_t* len)
{
	double val;
	char buf[32700];

	val = va_arg(argv, double);
	format.len -= get_double(format, val, buf);
	if (format.left) {
		ft_putstr(buf, len);
		while (format.len-- > 0)
			ft_putchar(' ', len);
	}
	else {
		while (format.len-- > 0)
			ft_putchar(' ', len);
		ft_putstr(buf, len);
	}
}