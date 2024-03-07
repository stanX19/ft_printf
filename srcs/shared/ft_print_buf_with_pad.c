/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_with_pad.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:03:51 by shatan            #+#    #+#             */
/*   Updated: 2024/03/07 17:07:23 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_padding(int pad_len, char pad_char, size_t *len)
{
	*len += pad_len;
	while (pad_len-- > 0)
		write(1, &pad_char, 1);
}

void	print_buf_with_pad_char(t_format fmt, char *buf, char pad_char, size_t *len)
{
	if (fmt.left)
	{
		ft_printf_putstr(buf, len);
		print_padding(fmt.len, pad_char, len);
	}
	else
	{
		print_padding(fmt.len, pad_char, len);
		ft_printf_putstr(buf, len);
	}
}

void	print_buf_with_pad(t_format fmt, char *buf, size_t *len)
{
	if (fmt.zero)
		print_buf_with_pad_char(fmt, buf, '0', len);
	else
		print_buf_with_pad_char(fmt, buf, ' ', len);
}
