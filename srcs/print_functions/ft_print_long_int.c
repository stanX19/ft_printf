/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:35:57 by stan              #+#    #+#             */
/*   Updated: 2024/03/10 12:57:02 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_long_int(t_format format, va_list *argv, size_t *len)
{
	long int	val;
	char		buf[50];

	val = va_arg(*argv, long int);
	get_int(&format, val, buf);
	print_buf_with_int_fmt(format, format.prefix, buf, len);
}
