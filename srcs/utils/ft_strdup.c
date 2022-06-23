#include "ft_printf.h"

char* ft_strdup(const char* s)
{
	size_t len;
	char* ret;

	if (!s)
		return 0;
	len = -1;
	while (s[++len])
		;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return 0;
	len = -1;
	while (s[++len])
		ret[len] = s[len];
	ret[len] = 0;
	return ret;
}