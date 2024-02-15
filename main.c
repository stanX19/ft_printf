#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include "ft_printf.h"

// typedef struct s_base
// {
// 	size_t		nbr;
// 	const char	*str;
// }	t_base;

// void	print_int(int val) {
// 	printf("%i", val);
// }

int	main(void)
{
	// char* s2 = 0;
	double x = 97.855;
	char *str;

	str = "|%-0.2f|\n";
	printf(str, x);
	ft_printf(str, x);
}