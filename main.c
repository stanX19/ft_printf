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
	//char* x = 0;
	long double x = -3123;
	char *str  = "|%-100.*Lf|\n";

	size_t a = printf(str, -100, x);
	size_t b = ft_printf(str, -100, x);

	printf("\nReturn %lu %lu\n", a, b);
}