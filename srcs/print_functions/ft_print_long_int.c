/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:35:57 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_int(t_format format, va_list argv, size_t *len)
{
	long int	val;
	char		buf[50];

	val = va_arg(argv, long int);
	if (format.zero && format.precicion == -1)
		format_zero(&format, val);
	format.len -= get_int(format, val, buf);
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
