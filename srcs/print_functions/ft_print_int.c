#include "ft_printf.h"

void print_int(format_t format, va_list argv, size_t* len)
{
	int val;
    char buf[32700];

    val = va_arg(argv, int);
    if (format.zero && format.precicion == -1)
        format_zero(&format, val);
    format.len -= get_int(format, val, buf);
    if (format.left)
	{
        ft_putstr(buf, len);
        while (format.len-- > 0)
            ft_putchar(' ', len);
    }
    else
	{
        while (format.len-- > 0)
            ft_putchar(' ', len);
        ft_putstr(buf, len);
    }
}