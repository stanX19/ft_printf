#include "ft_printf.h"

static size_t get_upper_hex(format_t format, unsigned int val, char* buf)
{
    char* base;

    base = "0123456789ABCDEF";
    if (format.hash)
    {
        ft_strcpy(buf, "0X");
        return get_unsigned_nbr_base(format, val, buf + 2, base) + 2;
    }
    return get_unsigned_nbr_base(format, val, buf, base);
}

void print_hex_upper(format_t format, va_list argv, size_t* len)
{
	unsigned int val;
    char buf[32700];

    val = va_arg(argv, unsigned int);
    format.len -= get_upper_hex(format, val, buf);
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