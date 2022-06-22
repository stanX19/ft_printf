#include "ft_printf.h"

void print_double(char* format_str, long double val, size_t* len) {
    format_t format;
    char buf[32700];

    format = read_format(format_str);
    if (val < 0.0)
        format.positive = "";
    format.len -= get_double(format, val, buf) + ft_strlen(format.positive);
    if (format.left) {
        ft_putstr(format.positive, len);
        ft_putstr(buf, len);
        while (format.len-- > 0)
            ft_putchar(' ', len);
    }
    else {
        while (format.len-- > 0)
            ft_putchar(' ', len);
        ft_putstr(format.positive, len);
        ft_putstr(buf, len);
    }
}