#include "ft_printf.h"

static void	recur(long long unsigned int nbr, char*buf, size_t*idx)
{
	if (nbr > 9)
		recur(nbr / 10, buf, idx);
	buf[(*idx)++] = nbr % 10 + 48;
}

size_t	get_unsigned(format_t format, long long unsigned int nbr, char*buf)
{
	char nbr_str[21];
	size_t	idx2;
	size_t	idx;

	idx = 0;
	recur(nbr, nbr_str, &idx2);
	nbr_str[idx2] = 0;
	format.precicion -= idx2;
	while (format.precicion-- > 0)
		buf[idx++] = '0';
	ft_strcpy(buf + idx, nbr_str);
	buf[idx + idx2] = 0;
	return idx + idx2;
}