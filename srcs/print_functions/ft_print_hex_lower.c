/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:26 by stan              #+#    #+#             */
/*   Updated: 2024/03/09 17:34:10 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_lower_hex(unsigned int val, char *buf)
{
	return (get_unsigned_nbr_base(val, buf, "0123456789abcdef"));
}

void	print_hex_lower(t_format format, va_list *argv, size_t *len)
{
	unsigned int	val;
	char			buf[25];
	char			*prefix;

	val = va_arg(*argv, unsigned int);
	if (format.hash)
		prefix = "0x";
	else
		prefix = "";
	get_lower_hex(val, buf);
	print_buf_with_int_fmt(format, prefix, buf, len);
}
