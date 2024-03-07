/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:30:17 by stan              #+#    #+#             */
/*   Updated: 2024/03/07 17:03:00 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_str(t_format format, va_list *argv, size_t *len)
{
	char	buf[5000];
	char	*src;

	if (format.precicion == -1)
		format.precicion = 4999;
	src = va_arg(*argv, char *);
	if (!src)
		ft_strlcpy(buf, "(null)", format.precicion + 1);
	else
		ft_strlcpy(buf, src, format.precicion + 1);
	format.len -= ft_strlen(buf);
	print_buf_with_pad(format, buf, len);
}
