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
	long long x = 9771203;
	char *str;

	str = "|%.5f|\n";
	printf(str, x);
	ft_printf(str, x);
}