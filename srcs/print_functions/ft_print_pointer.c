#include "ft_printf.h"

static size_t get_pointer(format_t format, long long unsigned int val, char* buf)
{
    ft_strcpy(buf, "0x");
    return get_nbr_base(format, val, buf + 2, "0123456789abcdef") + 2;
}

static size_t get_null(char* buf)
{
    ft_strcpy(buf, "(nil)");
    return 5;
}

void print_pointer(format_t format, va_list argv, size_t* len)
{
	unsigned long long int val;
    char buf[32700];

    val = va_arg(argv, unsigned long int);
    if (val)
        format.len -= get_pointer(format, val, buf);
    else
        format.len -= get_null(buf);
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