#include "ft_printf.h"

void	ft_putnbr(long int nb, size_t *len)
{
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-', len);
	}
	if (nb > 9)
		ft_putnbr(nb / 10, len);
	ft_putchar(nb % 10 + '0', len);
}
