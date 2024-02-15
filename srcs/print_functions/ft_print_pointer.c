/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:42 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_pointer(t_format format, long long unsigned int val,
		char *buf)
{
	ft_strcpy(buf, "0x");
	return (get_unsigned_nbr_base(format, val, buf + 2, "0123456789abcdef")
		+ 2);
}

static size_t	get_null(char *buf)
{
	ft_strcpy(buf, "(nil)");
	return (5);
}

void	print_pointer(t_format format, va_list argv, size_t *len)
{
	unsigned long long int	val;
	char					buf[32700];

	val = va_arg(argv, unsigned long int);
	if (val)
		format.len -= get_pointer(format, val, buf);
	else
		format.len -= get_null(buf);
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
