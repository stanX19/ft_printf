/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:38:42 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	get_binary(t_format format, unsigned long long int val,
		char *buf)
{
	char	*base;

	base = "01";
	if (format.hash && val > 0)
	{
		ft_strcpy(buf, "0b");
		return (get_unsigned_nbr_base(format, val, buf + 2, base) + 2);
	}
	return (get_unsigned_nbr_base(format, val, buf, base));
}

void	print_binary(t_format format, va_list argv, size_t *len)
{
	unsigned long long int	val;
	char					buf[513];

	val = va_arg(argv, long long unsigned int);
	if (format.zero && format.precicion == -1)
		format_zero(&format, val);
	format.len -= get_binary(format, val, buf);
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
