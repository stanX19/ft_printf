/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:10 by stan              #+#    #+#             */
/*   Updated: 2024/03/10 13:55:11 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_hex_upper(t_format format, va_list *argv, size_t *len)
{
	unsigned int	val;
	char			buf[25];

	val = va_arg(*argv, unsigned int);
	if (format.hash && val > 0)
		format.prefix = "0X";
	get_unsigned_nbr_base(val, buf, "0123456789ABCDEF");
	print_buf_with_int_fmt(format, buf, len);
}
