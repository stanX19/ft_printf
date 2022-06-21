#include "ft_printf.h"

static inline void read_double_format(char* format, int* len, int* decimal) {
    int i;

    *len = 0;
    *decimal = 6;
    i = 0;
    while (format[i] && format[i] >= '0' && format[i] <= '9')
        *len = *len * 10 + format[i++] - 48;
    if (format[i] && format[i] == '.')
    {
        i++;
        *decimal = 0;
        while (format[i] && format[i] >= '0' && format[i] <= '9')
            *decimal = *decimal * 10 + format[i++] - 48;
    }
}

static inline void add_decimal(int* idx, char* buf, long double val, int decimal) {
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

static inline void add_intiger(int* idx, char* buf, int val) {
    int place;

    place = 1;
    while (place * 10 < val)
        place *= 10;
    while (place > 0) {
        buf[(*idx)++] = (val / place) % 10 + 48;
        place /= 10;
    }
}

void print_double(char* format, long double val, size_t*len) {
    int idx;
    char buf[100000];
    int length;
    int decimal;

    read_double_format(format, &length, &decimal);
    idx = 0;
    if (val < 0)
    {
        val = -val;
        buf[idx++] = '-';
    }
    add_intiger(&idx, buf, val);
    if (decimal)
        add_decimal(&idx, buf, val, decimal);
    buf[idx] = 0;
    length -= idx;
    while (length-- > 0)
        ft_putchar(' ', len);
    ft_putstr(buf, len);
}