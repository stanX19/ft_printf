/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:38:30 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 19:08:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_char(t_format format, va_list argv, size_t *len)
{
	if (format.left)
	{
		ft_printf_putchar(va_arg(argv, int), len);
		while (--format.len > 0)
			ft_printf_putchar(' ', len);
		return ;
	}
	while (--format.len > 0)
		ft_printf_putchar(' ', len);
	ft_printf_putchar(va_arg(argv, int), len);
}
