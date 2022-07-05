#include "ft_printf.h"

void	ft_putstr(const char *str, size_t*len)
{
	size_t idx;

	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	idx = ft_strlen(str);
	*len += idx;
	write(1, str, idx);
}
