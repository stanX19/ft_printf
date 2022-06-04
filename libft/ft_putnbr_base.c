#include "libft.h"

static int	is_valid(char* base, int basenbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < basenbr)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < basenbr)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(long int nbr, char* base, size_t*len)
{
	int			basenbr;

	basenbr = -1;
	while (base[basenbr++ + 1])
		;
	if (!is_valid(base, basenbr + 1))
		return;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr >= basenbr)
		ft_putnbr_base(nbr / basenbr, base, len);
	ft_putchar(base[nbr % basenbr], len);
}