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
	// char* x = 0;
	long int x = 3;
	char *str  = "|%-100.*b|\n";

	size_t a = 1;//printf(str, x, x);
	size_t b = ft_printf(str, x, x);

	printf("\nReturn %lu %lu\n", a, b);
}