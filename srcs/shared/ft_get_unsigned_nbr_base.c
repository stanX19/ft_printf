#include "ft_printf.h"

typedef struct s_base
{
	size_t nbr;
	const char *str;
} base_t;

static void	recur(long long unsigned int val, char*buf, size_t*idx, base_t base)
{
	if (val >= base.nbr)
		recur(val / base.nbr, buf, idx, base);
	buf[(*idx)++] = base.str[val % base.nbr];
}

size_t	get_unsigned_nbr_base(format_t format, long long unsigned int val, char*buf, const char*basestr)
{
	char base_buf[65];
	size_t	idx2;
	size_t	idx;
	base_t	base =
	{
		ft_strlen(basestr), basestr
	};
	idx = 0;
	idx2 = 0;
	recur(val, base_buf, &idx2, base);
	base_buf[idx2] = 0;
	format.precicion -= idx2;
	while (format.precicion-- > 0)
		buf[idx++] = '0';
	ft_strcpy(buf + idx, base_buf);
	return idx + idx2;
}