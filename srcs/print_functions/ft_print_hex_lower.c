#include "ft_printf.h"

static size_t get_lower_hex(format_t format, unsigned int val, char* buf)
{
    char* base;

    base = "0123456789abcdef";
    if (format.hash && val > 0)
    {
        ft_strcpy(buf, "0x");
        return get_unsigned_nbr_base(format, val, buf + 2, base) + 2;
    }
    return get_unsigned_nbr_base(format, val, buf, base);
}

void print_hex_lower(format_t format, va_list argv, size_t* len)
{
	unsigned int val;
    char buf[32700];

    val = va_arg(argv, unsigned int);
    if (format.zero && format.precicion == -1)
        format_zero(&format, val);
    format.len -= get_lower_hex(format, val, buf);
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