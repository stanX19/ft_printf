#include "ft_printf.h"

static size_t get_binary(format_t format, unsigned long long int val, char* buf)
{
    char* base;

    base = "01";
    if (format.hash && val > 0)
    {
        ft_strcpy(buf, "0b");
        return get_unsigned_nbr_base(format, val, buf + 2, base) + 2;
    }
    return get_unsigned_nbr_base(format, val, buf, base);
}

void print_binary(format_t format, va_list argv, size_t* len)
{
	unsigned long long int val;
    char buf[32700];

    val = va_arg(argv, long long unsigned int);
    if (format.zero && format.precicion == -1)
        format_zero(&format, val);
    format.len -= get_binary(format, val, buf);
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