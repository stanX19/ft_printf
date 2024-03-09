/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:42 by stan              #+#    #+#             */
/*   Updated: 2024/03/09 16:29:32 by stan             ###   ########.fr       */
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
	get_pointer(val, buf);
	print_buf_with_int_fmt(format, "0x", buf, len);
}
