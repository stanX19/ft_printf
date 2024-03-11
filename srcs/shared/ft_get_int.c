/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:25:17 by stan              #+#    #+#             */
/*   Updated: 2024/03/11 13:40:02 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	recur(long long unsigned int nbr, char *buf, size_t *idx)
{
	if (nbr > 9)
		recur(nbr / 10, buf, idx);
	buf[(*idx)++] = nbr % 10 + 48;
}

size_t	get_int(t_format *format, long long int nbr, char *buf)
{
	unsigned long long int	val;
	size_t					idx;

	idx = 0;
	val = nbr;
	if (nbr < 0)
	{
		format->prefix = "-";
		val = -nbr;
	}
	recur(val, buf, &idx);
	buf[idx] = '\0';
	return (idx);
}
