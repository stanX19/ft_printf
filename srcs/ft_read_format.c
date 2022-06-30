#include "ft_printf.h"

static void default_format_value(format_t* format)
{
    format->len = 0;
    format->precicion = -1;
    format->positive = "";
    format->left = 0;
    format->hash = 0;
    format->zero = 0;
}

static void read_format1(format_t* format, const char* format_str, size_t *idx)
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
        else if (format_str[(*idx)] == '0')
            format->zero = 1;
        else
            return;
    }
}

format_t read_format(const char* format_str, size_t *idx)
{
    format_t format;

    default_format_value(&format);
    *idx = -1;
    read_format1(&format, format_str, idx);
    while (format_str[*idx] && ft_isdigit(format_str[*idx]))
        format.len = format.len * 10 + format_str[(*idx)++] - 48;
    if (format_str[*idx] && format_str[*idx] == '.')
    {
        (*idx)++;
        format.precicion = 0;
        while (format_str[*idx] && ft_isdigit(format_str[*idx]))
            format.precicion = format.precicion * 10 + format_str[(*idx)++] - 48;
    }
    format.func = match_function(format_str + *idx, idx);
    return format;
}