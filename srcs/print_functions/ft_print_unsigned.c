#include "ft_printf.h"

void print_unsigned(format_t format, va_list argv, size_t* len)
{
	unsigned int val;
    char buf[32700];

    val = va_arg(argv, unsigned int);
    format.len -= get_unsigned(format, val, buf);
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