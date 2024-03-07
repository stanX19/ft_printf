/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:32:30 by stan              #+#    #+#             */
/*   Updated: 2024/03/07 17:03:00 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_unsigned(t_format format, va_list *argv, size_t *len)
{
	long unsigned int	val;
	char				buf[50];

	val = va_arg(*argv, long unsigned int);
	if (format.zero && format.precicion == -1)
		format_zero(&format, val);
	format.len -= get_unsigned_nbr_base(val, buf, "0123456789");
	print_buf_with_pad(format, buf, len);
}
