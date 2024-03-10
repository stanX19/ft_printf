/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_with_pad.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:03:51 by shatan            #+#    #+#             */
/*   Updated: 2024/03/10 12:57:41 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_buf_with_pad_char(t_format fmt, const char *buf, char pad_char, size_t *len)
{
	if (fmt.left)
	{
		ft_printf_putstr(buf, len);
		ft_printf_putnchar(pad_char, fmt.len, len);
	}
	else
	{
		ft_printf_putnchar(pad_char, fmt.len, len);
		ft_printf_putstr(buf, len);
	}
}

void	print_buf_with_pad(t_format fmt, const char *buf, size_t *len)
{
	if (fmt.zero)
		print_buf_with_pad_char(fmt, buf, '0', len);
	else
		print_buf_with_pad_char(fmt, buf, ' ', len);
}
