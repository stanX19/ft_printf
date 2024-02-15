/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:17 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 20:04:51 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_str(t_format format, va_list argv, size_t *len)
{
	char	buf[5000];
	char	*src;

	if (format.precicion == -1)
		format.precicion = 4999;
	src = va_arg(argv, char *);
	if (!src)
		ft_strlcpy(buf, "(null)", format.precicion + 1);
	else
		ft_strlcpy(buf, src, format.precicion + 1);
	format.len -= ft_strlen(buf);
	if (format.left)
	{
		ft_printf_putstr(buf, len);
		while (format.len-- > 0)
			ft_printf_putchar(' ', len);
		return ;
	}
	while (format.len-- > 0)
		ft_printf_putchar(' ', len);
	ft_printf_putstr(buf, len);
}
