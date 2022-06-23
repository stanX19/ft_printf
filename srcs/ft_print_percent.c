#include "ft_printf.h"

void print_percent(format_t format, va_list argv, size_t*idx){
    (void)argv;
    (void)format;
    ft_putchar('%', idx);
}