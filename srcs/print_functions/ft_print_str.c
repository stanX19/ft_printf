#include "ft_printf.h"

void	print_str(format_t format, va_list argv, size_t* len)
{
	char buf[5000];

	ft_strncpy(buf, va_arg(argv, char*), format.precicion);
	format.len -= ft_strlen(buf);
	if (format.left)
	{
		ft_putstr(buf, len);
		while (format.len-- > 0)
			ft_putchar(' ', len);
		return;
	}
	while (format.len-- > 0)
		ft_putchar(' ', len);
	ft_putstr(buf, len);
}