/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unsigned_nbr_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:22:42 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	recur(long long unsigned int val, char *buf, size_t *idx,
		t_base base)
{
	if (val >= base.nbr)
		recur(val / base.nbr, buf, idx, base);
	buf[(*idx)++] = base.str[val % base.nbr];
}

size_t	get_unsigned_nbr_base(t_format format, long long unsigned int val,
		char *buf, const char *basestr)
{
	char	base_buf[65];
	size_t	idx2;
	size_t	idx;
	t_base	base;

	base.nbr = ft_strlen(basestr);
	base.str = basestr;
	idx = 0;
	idx2 = 0;
	recur(val, base_buf, &idx2, base);
	base_buf[idx2] = 0;
	format.precicion -= idx2;
	while (format.precicion-- > 0)
		buf[idx++] = '0';
	ft_strcpy(buf + idx, base_buf);
	return (idx + idx2);
}
