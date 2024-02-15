/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:36:21 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:36:21 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_double(t_format format, va_list argv, size_t *len)
{
	long double	val;
	char		buf[100];

	val = va_arg(argv, long double);
	format.len -= get_double(format, val, buf);
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
