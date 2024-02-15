/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:25:17 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	recur(long long unsigned int nbr, char *buf, size_t *idx)
{
	if (nbr > 9)
		recur(nbr / 10, buf, idx);
	buf[(*idx)++] = nbr % 10 + 48;
}

size_t	get_int(t_format format, long long int nbr, char *buf)
{
	unsigned long long int	val;
	char					nbr_str[21];
	size_t					idx2;
	size_t					idx;

	idx = 0;
	idx2 = 0;
	val = nbr;
	if (nbr < 0)
	{
		buf[idx++] = '-';
		val = -nbr;
	}
	else if (*format.positive)
		buf[idx++] = *format.positive;
	recur(val, nbr_str, &idx2);
	nbr_str[idx2] = 0;
	format.precicion -= idx2;
	while (format.precicion-- > 0)
		buf[idx++] = '0';
	ft_strcpy(buf + idx, nbr_str);
	return (idx + idx2);
}
