#include "ft_printf.h"

char*	ft_strncpy(char* dst, char* src, size_t n)
{
	size_t i;

	if (!src)
		src = "(null)";
	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return dst;
}