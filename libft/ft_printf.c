#include "libft.h"

int count_args(char* str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i++] == '%')
		{
			ret++;
			if (str[i])
				i++;
		}
	}
	return ret;
}
size_t ft_printf(char* str, ...)
{
	size_t len;
	int argc;

	len = 0;
	argc = count_args(str);
}