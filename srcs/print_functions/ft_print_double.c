#include "ft_printf.h"

static inline void add_decimal(size_t* idx, char* buf, long double val, int decimal) {
    unsigned long long int store;
    unsigned long long int place;
    int i;
    char temp;

    i = -1;
    place = 10;
    while (++i < decimal)
        place *= 10;
    store = (val - (int)val) * place;
    if (store % 10 > 4)
        store += 10;
    buf[(*idx)++] = '.';
    while (decimal-- > 0 && place > 9)
    {
        place /= 10;
        temp = (store / place) % 10 + 48;
        buf[(*idx)++] = temp;
    }
}

static inline void add_intiger(size_t* idx, char* buf, int val) {
    int place;

    place = 1;
    while (place * 10 < val)
        place *= 10;
    while (place > 0) {
        buf[(*idx)++] = (val / place) % 10 + 48;
        place /= 10;
    }
}

static size_t get_double(format_t format, long double val, char *buf) {
    size_t idx;

    idx = 0;
    if (val < 0)
    {
        val = -val;
        buf[idx++] = '-';
    }
    else if (format.positive[0])
        buf[idx++] = format.positive[0];
    add_intiger(&idx, buf, val);
    if (format.precicion)
        add_decimal(&idx, buf, val, format.precicion);
    buf[idx] = 0;
    return idx;
}

void print_double(format_t format, va_list argv, size_t* len)
{
    long double val;
    char buf[32700];

    val = va_arg(argv, long double);
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