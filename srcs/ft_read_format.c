#include "ft_printf.h"

format_t read_format(char* format_str) {
    format_t ret;
    int i;

    ret.len = 0;
    ret.precicion = 6;
    i = -1;
    ret.positive = "";
    ret.left = 0;
    while (format_str[++i]) {
        if (format_str[i] == '+')
            ret.positive = "+";
        else if (format_str[i] == ' ')
            ret.positive = " ";
        else if (format_str[i] == '-')
            ret.left = 1;
        else
            break;
    }
    while (format_str[i] && format_str[i] >= '0' && format_str[i] <= '9')
        ret.len = ret.len * 10 + format_str[i++] - 48;
    if (format_str[i] && format_str[i] == '.')
    {
        i++;
        ret.precicion = 0;
        while (format_str[i] && format_str[i] >= '0' && format_str[i] <= '9')
            ret.precicion = ret.precicion * 10 + format_str[i++] - 48;
    }
    return ret;
}