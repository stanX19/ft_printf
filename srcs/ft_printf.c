/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:41:30 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:41:30 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

static size_t	print_format(char *format_str, va_list argv, size_t *len)
{
	size_t		idx;
	t_format	format;

	format = read_format(format_str, &idx);
	format.func(format, argv, len);
	return (idx);
}

size_t	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	argv;

	va_start(argv, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += print_format((char *)(str + i + 1), argv, &len);
		else
			ft_printf_putchar(str[i], &len);
		i++;
	}
	va_end(argv);
	return (len);
}
