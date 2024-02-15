/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:32:30 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_unsigned(t_format format, va_list argv, size_t *len)
{
	long unsigned int	val;
	char				buf[50];

	val = va_arg(argv, long unsigned int);
	if (format.zero && format.precicion == -1)
		format_zero(&format, val);
	format.len -= get_unsigned_nbr_base(format, val, buf, "0123456789");
	if (format.left)
	{
		ft_printf_putstr(buf, len);
		while (format.len-- > 0)
			ft_printf_putchar(' ', len);
	}
	else
	{
		while (format.len-- > 0)
			ft_printf_putchar(' ', len);
		ft_printf_putstr(buf, len);
	}
}
