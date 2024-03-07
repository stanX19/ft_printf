/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:42 by stan              #+#    #+#             */
/*   Updated: 2024/03/07 17:04:32 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_pointer(long long unsigned int val,
		char *buf)
{
	return (get_unsigned_nbr_base(val, buf, "0123456789abcdef"));
}

void	print_pointer(t_format format, va_list *argv, size_t *len)
{
	unsigned long long int	val;
	char					buf[21];

	val = va_arg(*argv, unsigned long int);
	if (format.precicion > 0)
	{
		format.zero = 1;
		format.len = format.precicion;
	}
	format.len -= get_pointer(val, buf);
	if (format.zero)
	{
		ft_printf_putstr("0x", len);
		print_buf_with_pad_char(format, buf, '0', len);
	}
	else
	{
		ft_memmove(buf + 2, buf, sizeof(buf) - 2);
		ft_memcpy(buf, "0x", 2);
		print_buf_with_pad(format, buf, len);
	}
}
