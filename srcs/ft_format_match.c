#include "ft_printf.h"

int	format_match(char*	src, char*	target)
{
	int	i;

	i = 0;
	while (src[i] && target[i] && src[i] == target[i])
		i++;
	if (src[i] == 0)
		return i;
	return 0;
}
