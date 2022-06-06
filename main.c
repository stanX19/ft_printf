#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int len;
	int x = -111;
	len = ft_printf("%%%%%%%p\n", &x);
	printf("%i\n", len == printf("%%%%%%%p\n", &x));
	//ft_printf("%i", len);
	(void)len;
}