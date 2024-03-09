/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:10 by stan              #+#    #+#             */
/*   Updated: 2024/03/09 17:30:46 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_upper_hex(unsigned int val, char *buf)
{
	return (get_unsigned_nbr_base(val, buf, "0123456789ABCDEF"));
}

void	print_hex_upper(t_format format, va_list *argv, size_t *len)
{
	unsigned int	val;
	char			buf[25];
	char			*prefix;

	val = va_arg(*argv, unsigned int);
	if (format.hash)
		prefix = "0X";
	else
		prefix = "";
	get_upper_hex(val, buf);
	print_buf_with_int_fmt(format, prefix, buf, len);
}
