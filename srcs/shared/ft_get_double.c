/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:26:20 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:26:20 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline void	add_decimal(size_t *idx, char *buf, long double val,
		int decimal)
{
	unsigned long long int	store;
	unsigned long long int	place;
	int						i;

	i = -1;
	place = 10;
	while (++i < decimal && i < 18)
		place *= 10;
	store = (val - ((long long unsigned int)val)) * place;
	if (store % 10 > 4)
		store += 10;
	buf[(*idx)++] = '.';
	while (decimal-- > 0 && place > 9)
	{
		place /= 10;
		buf[(*idx)++] = (store / place) % 10 + 48;
	}
	while (decimal-- > -1)
		buf[(*idx)++] = '0';
}

static inline void	add_intiger(size_t *idx, char *buf,
		long long unsigned int val)
{
	long long unsigned int	place;

	place = 1;
	while (place * 10 < val)
		place *= 10;
	while (place > 0)
	{
		buf[(*idx)++] = (val / place) % 10 + 48;
		place /= 10;
	}
}

size_t	get_double(t_format format, long double val, char *buf)
{
	size_t	idx;
	char	*temp_buf;
	int		i;

	idx = 0;
	if (val < 0)
	{
		val = -val;
		buf[idx++] = '-';
	}
	else if (format.positive[0])
		buf[idx++] = format.positive[0];
	add_intiger(&idx, buf, val);
	if (format.precicion == -1)
		format.precicion = 6;
	if (format.precicion)
		add_decimal(&idx, buf, val, format.precicion);
	if (format.zero && (size_t)format.len > idx)
	{
		temp_buf = buf + !ft_isdigit(buf[0]);
		format.len -= idx;
		ft_memmove(temp_buf + format.len, temp_buf, idx);
		i = 0;
		while (i < format.len)
			temp_buf[i++] = '0';
	}
	else
		format.len = 0;
	buf[idx + format.len] = 0;
	return (idx + format.len);
}
