#include "ft_printf.h"
#include <stdio.h>

void print_int(format_t format, va_list argv, size_t* len)
{
	long long int val;
    char buf[32700];

    val = va_arg(argv, int);
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