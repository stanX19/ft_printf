#include "ft_printf.h"

void	ft_putstr(const char *str, size_t*len)
{
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*str)
	{
		ft_putchar(*(str++), len);
	}
}
