#include "ft_printf.h"

struct s2_format {
    char* positive;
    int len;
    int precicion;
    short int left;
};

static struct s2_format read_format(char* format_str) {
    struct s2_format ret;
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

void print_double(char* format_str, long double val, size_t* len) {
    struct s2_format format;
    char buf[10000];

    format = read_format(format_str);
    if (val < 0.0)
        format.positive = "";
    format.len -= get_double(format.precicion, val, buf) + ft_strlen(format.positive);
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