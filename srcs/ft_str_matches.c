#include "ft_printf.h"

int format_match(char* src, char* target) {
	int i;

	i = 0;
	while (src[i] && target[i] && src[i] == target[i])
		i++;
	return (src[i] == 0);
}