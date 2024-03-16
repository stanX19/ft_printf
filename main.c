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
	//char* x = "LOL";
	unsigned long long int x = 10000;
	char *str  = "[%d]\n";

	size_t a = printf(str, x);
	size_t b = ft_printf(str, x);

	printf("\nReturn %lu %lu\n", a, b);
}