/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:32:30 by stan              #+#    #+#             */
/*   Updated: 2024/03/10 13:07:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_unsigned(t_format format, va_list *argv, size_t *len)
{
	long unsigned int	val;
	char				buf[50];

	val = va_arg(*argv, long unsigned int);
	get_unsigned_nbr_base(val, buf, "0123456789");
	print_buf_with_int_fmt(format, buf, len);
}
