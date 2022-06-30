#include "ft_printf.h"

static size_t	print_format(char *format_str, va_list argv, size_t* len)
{
	size_t		idx;
	format_t	format;

	format = read_format(format_str, &idx);
	format.func(format, argv, len);
	return idx;
}

size_t	ft_printf(const char* str, ...)
{
	size_t i;
	size_t len;
	va_list argv;

	va_start(argv, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += print_format((char*)(str + i + 1), argv, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(argv);
	return len;
}