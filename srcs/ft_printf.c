#include "ft_printf.h"

static void print_ptr(unsigned long int ptr, size_t *len)
{
	char *base;

	base = "0123456789abcdef";
	if (ptr >= 16)
		print_ptr(ptr / 16, len);
	ft_putchar(base[ptr % 16], len);
}

static void	print_format(char c, va_list argv, size_t* len)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(argv, int), len);
	else if (c == 'c')
		ft_putchar(va_arg(argv, int), len);
	else if (c == 's')
		ft_putstr(va_arg(argv, char*), len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		print_ptr(va_arg(argv, unsigned long int), len);
	}
	else if (c == 'u')
		ft_putnbr((long int)va_arg(argv, unsigned int), len);
	else if (c == 'x')
		ft_putnbr_base((long long int)va_arg(argv, unsigned int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_base((long long int)va_arg(argv, unsigned int), "0123456789ABCDEF", len);
	else if (c == '%')
		ft_putchar('%', len);
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
			print_format(str[++i], argv, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(argv);
	return len;
}