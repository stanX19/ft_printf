#include "../ft_printf.h"

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

static void	recur(long long int nbr, char* base, int basenbr, size_t* len)
{
	if (nbr >= basenbr)
		recur(nbr / basenbr, base, basenbr, len);
	ft_putchar(base[nbr % basenbr], len);
}

void	ft_putnbr_base(long long int nbr, char* base, size_t*len)
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
	recur(nbr, base, basenbr, len);
}