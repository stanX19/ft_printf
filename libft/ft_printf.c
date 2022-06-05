#include "libft.h"

//static int	count_args(char* str)
//{
//	int i;
//	int ret;
//
//	i = 0;
//	ret = 0;
//	while (str[i])
//	{
//		if (str[i++] == '%')
//		{
//			ret++;
//			if (str[i])
//				i++;
//		}
//	}
//	return ret;
//}

static void	print_format(char c, va_list argv, size_t* len)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(argv, int), len);
	else if (c == 'c')
		ft_putchar(va_arg(argv, int), len);
	else if (c == 's')
		ft_putstr(va_arg(argv, char*), len);
	else if (c == 'p')
		ft_putnbr_base((long)va_arg(argv, void*), "0123456789abcdefg", len);
	else if (c == 'u')
		ft_putnbr((long int)va_arg(argv, unsigned int), len);
	else if (c == 'x')
		ft_putnbr_base(va_arg(argv, int), "0123456789abcdefg", len);
	else if (c == 'X')
		ft_putnbr_base(va_arg(argv, int), "0123456789ABCDEFG", len);
	else if (c == '%')
		ft_putchar('%', len);
}

size_t	ft_printf(char* str, ...)
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
			print_format(str[i + 1], argv, &len);
		else
			ft_putchar(str[i], &len);
	}
	va_end(argv);
	return len;
}