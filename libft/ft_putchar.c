#include "libft.h"

void ft_putchar(char c, size_t*len)
{
	(*len)++;
	write(1, &c, 1);
}