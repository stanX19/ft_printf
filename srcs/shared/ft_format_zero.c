#include "ft_printf.h"

void format_zero(format_t* format, long long int val)
{
    format->precicion = format->len;
    format->len = 0;
    if (val < 0)
        format->precicion -= 1;
}