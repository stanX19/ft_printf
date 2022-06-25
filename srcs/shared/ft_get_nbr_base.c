#include "ft_printf.h"

static void	recur(long long unsigned int val, char*buf, size_t*idx, char*base)
{
	size_t len;

	len = ft_strlen(base);
	if (val >= len)
		recur(val / len, buf, idx, base);
	buf[(*idx)++] = base[val % len];
}

size_t	get_nbr_base(format_t format, long long unsigned int val, char*buf, char*base)
{
	char base_str[21];
	size_t	idx2;
	size_t	idx;
	
	idx = 0;
	idx2 = 0;
	recur(val, base_str, &idx2, base);
	base_str[idx2] = 0;
	format.precicion -= idx2;
	while (format.precicion-- > 0)
		buf[idx++] = '0';
	ft_strcpy(buf + idx, base_str);
	return idx + idx2;
}