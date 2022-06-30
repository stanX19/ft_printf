#include "ft_printf.h"

typedef struct s_fdict
{
    char key[5];
    funcptr func;
} t_fdict;

static int	format_cmp(const char* src, const char* target)
{
    int	i;

    i = 0;
    while (src[i] && target[i] && src[i] == target[i])
        i++;
    if (src[i] == 0)
        return i;
    return 0;
}

static funcptr iterate(const t_fdict* dict, const char* format_str, size_t* idx)
{
    size_t      i;
    size_t      len;

    i = 0;
    len = 0;
    while (dict[i].key[0])
    {
        len = format_cmp(dict[i].key, format_str);
        if (len > 0)
        {
            *idx += len;
            return dict[i].func;
        }
        i++;
    }
    if (*format_str == '%')
        (*idx)++;
    return print_percent;
}

funcptr match_function(const char* format_str, size_t* idx)
{
    static t_fdict  dict[] = 
    {
        {"c", print_char},
        {"s", print_str},
        {"f", print_double},
        {"Lf", print_long_double},
        {"d", print_int},
        {"i", print_int},
        {"li", print_long_int},
        {"lli", print_long_int},
        {"u", print_unsigned},
        {"p", print_pointer},
        {"x", print_hex_lower},
        {"X", print_hex_upper},
        {"b", print_binary},
    };
    return iterate(dict, format_str, idx);
}