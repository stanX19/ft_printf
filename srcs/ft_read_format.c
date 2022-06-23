#include "ft_printf.h"
#define F_COUNT 6

static void assign(char strs[F_COUNT][5], void (*funcs[F_COUNT])(), char*str, funcptr func)
{
    static int idx;

    if (idx >= F_COUNT)
        return ;
    ft_strcpy(strs[idx], str);
    funcs[idx] = func;
    idx++;
}

static void format_init(char strs[F_COUNT][5], void (*funcs[F_COUNT])())
{
    assign(strs, funcs, "c", print_char);
    assign(strs, funcs, "f", print_double);
    assign(strs, funcs, "Lf", print_double);
    assign(strs, funcs, "i", print_int);
    assign(strs, funcs, "li", print_long_int);
    assign(strs, funcs, "lli", print_long_int);
}

funcptr match_function(char* format_str, size_t *idx){
    size_t      i;
    size_t      len;
    static char strs[F_COUNT][5];
    static void (*funcs[F_COUNT])();

    if (**strs == 0)
        format_init(strs, funcs);
    i = 0;
    len = 0;
    while (i < F_COUNT)
    {
        len = format_match(strs[i], format_str);
        if (len > 0)
        {
            *idx += len;
            return funcs[i];
        }
        i++;
    }
    if (*format_str == '%')
        (*idx)++;
    return print_percent;
}

static void read_format1(format_t* format, char* format_str, size_t *idx)
{
    while (format_str[++(*idx)])
    {
        if (format_str[(*idx)] == '+')
            format->positive = "+";
        else if (format_str[(*idx)] == ' ')
            format->positive = " ";
        else if (format_str[(*idx)] == '-')
            format->left = 1;
        else if (format_str[(*idx)] == '#')
            format->hash = 1;
        else
            return;
    }
}
format_t read_format(char* format_str, size_t *idx)
{
    format_t format;
    
    format.len = 0;
    format.precicion = 6;
    format.positive = "";
    format.left = 0;
    (*idx) = -1;
    read_format1(&format, format_str, idx);
    while (format_str[(*idx)] && format_str[(*idx)] >= '0' && format_str[(*idx)] <= '9')
        format.len = format.len * 10 + format_str[(*idx)++] - 48;
    if (format_str[(*idx)] && format_str[(*idx)] == '.')
    {
        (*idx)++;
        format.precicion = 0;
        while (format_str[(*idx)] && format_str[(*idx)] >= '0' && format_str[(*idx)] <= '9')
            format.precicion = format.precicion * 10 + format_str[(*idx)++] - 48;
    }
    format.func = match_function(format_str + *idx, idx);
    return format;
}