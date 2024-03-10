/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buf_with_fmt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:03:51 by shatan            #+#    #+#             */
/*   Updated: 2024/03/10 13:47:10 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_buf_with_middle_zeros(const char *prefix, int pad_len, const char *suffix, size_t *len)
{
	ft_printf_putstr(prefix, len);
	ft_printf_putnchar('0', pad_len, len);
	ft_printf_putstr(suffix, len);
}

void	print_buf_with_int_fmt(t_format fmt, const char *buf, size_t *len)
{
	int	buflen;
	
	buflen = ft_strlen(buf);
	if (fmt.zero && fmt.precicion <= -1 && fmt.prefix[0])
		fmt.precicion += fmt.len;
	else if (fmt.zero && fmt.precicion <= -1)
		fmt.precicion += fmt.len + 1;
	fmt.precicion -= buflen;
	fmt.precicion = (fmt.precicion >= 0) * fmt.precicion;
	fmt.len -= ft_strlen(fmt.prefix) + fmt.precicion + buflen;
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

void	print_buf_with_double_fmt(t_format fmt, const char *buf, size_t *len)
{
	int	buflen;
	
	buflen = ft_strlen(buf);
	fmt.precicion = (fmt.precicion >= 0) * fmt.precicion;
	fmt.len -= fmt.precicion + buflen;
	if (fmt.left)
	{
		ft_printf_putstr(buf, len);
		ft_printf_putnchar('0', fmt.precicion, len);
		ft_printf_putnchar(' ', fmt.len, len);
	}
	else
	{
		ft_printf_putnchar(' ', fmt.len, len);
		ft_printf_putstr(buf, len);
		ft_printf_putnchar('0', fmt.precicion, len);
	}
}

void	print_buf_with_str_fmt(t_format fmt, const char *buf, size_t *len)
{
	int	buflen;
	
	buflen = ft_strlen(buf);
	if (fmt.precicion == -1 || fmt.precicion > buflen)
		fmt.precicion = buflen;
	fmt.len -= fmt.precicion;
	if (fmt.left)
	{
		ft_printf_putnstr(buf, fmt.precicion, len);
		ft_printf_putnchar(' ', fmt.len, len);
	}
	else
	{
		ft_printf_putnchar(' ', fmt.len, len);
		ft_printf_putnstr(buf, fmt.precicion, len);
	}
}
