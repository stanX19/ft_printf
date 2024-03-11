/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_with_int_fmt.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:03:51 by shatan            #+#    #+#             */
/*   Updated: 2024/03/11 13:40:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static void	print_buf_with_middle_zeros(const char *prefix, int pad_len,
	const char *suffix, size_t *len)
{
	ft_printf_putstr(prefix, len);
	ft_printf_putnchar('0', pad_len, len);
	ft_printf_putstr(suffix, len);
}

// fmt.precicion -> remaining precicion to fill
// fmt.len -> remaining empty space to fill
// somehow precicion decreases when there is a sign / prefix
// precicion cannot be negative
static void	preprocess_int_format(t_format *fmt, const char *buf)
{
	int	buflen;
	int	prefix_len;

	buflen = ft_strlen(buf);
	prefix_len = ft_strlen(fmt->prefix);
	if (fmt->zero && fmt->precicion == -1)
	{
		if (prefix_len != 0)
			fmt->precicion += fmt->len + 1 - prefix_len;
		else
			fmt->precicion += fmt->len + 1;
	}
	fmt->precicion -= buflen;
	fmt->precicion = (fmt->precicion >= 0) * fmt->precicion;
	fmt->len -= prefix_len + fmt->precicion + buflen;
}

void	print_buf_int_fmt(t_format fmt, const char *buf, size_t *len)
{
	preprocess_int_format(&fmt, buf);
	if (fmt.left)
	{
		print_buf_with_middle_zeros(fmt.prefix, fmt.precicion, buf, len);
		ft_printf_putnchar(' ', fmt.len, len);
	}
	else
	{
		ft_printf_putnchar(' ', fmt.len, len);
		print_buf_with_middle_zeros(fmt.prefix, fmt.precicion, buf, len);
	}
}
