/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/02/15 18:26:20 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:26:20 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static inline void	add_decimal(int *idx, char *buf, long double val,
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

static inline void	add_integer(int *idx, char *buf,
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

static void	pad_with_zeros(int *idx, char *buf, int total_length)
{
	int	i;
	int	displacement;

	if (total_length <= *idx)
		return ;
	if (!ft_isdigit(buf[0]))
		buf++;
	displacement = total_length - *idx;
	ft_memmove(buf + displacement, buf, *idx);
	*idx += displacement;
	i = 0;
	while (i < displacement)
		buf[i++] = '0';
}

size_t	get_double(t_format format, long double val, char *buf)
{
	int	idx;

	idx = 0;
	if (val < 0)
	{
		val = -val;
		buf[idx++] = '-';
	}
	else if (format.positive[0])
		buf[idx++] = format.positive[0];
	add_integer(&idx, buf, val);
	if (format.precicion == -1)
		format.precicion = 6;
	if (format.precicion)
		add_decimal(&idx, buf, val, format.precicion);
	if (format.zero && format.len > idx)
		pad_with_zeros(&idx, buf, format.len);
	buf[idx] = 0;
	return (idx);
}
