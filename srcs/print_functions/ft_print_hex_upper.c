/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:37:10 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_upper_hex(t_format format, unsigned int val, char *buf)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (format.hash && val > 0)
	{
		ft_strcpy(buf, "0X");
		return (get_unsigned_nbr_base(format, val, buf + 2, base) + 2);
	}
	return (get_unsigned_nbr_base(format, val, buf, base));
}

void	print_hex_upper(t_format format, va_list argv, size_t *len)
{
	unsigned int	val;
	char			buf[32700];

	val = va_arg(argv, unsigned int);
	if (format.zero && format.precicion == -1)
		format_zero(&format, val);
	format.len -= get_upper_hex(format, val, buf);
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
