/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:38:30 by stan              #+#    #+#             */
/*   Updated: 2024/03/07 17:06:38 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	print_char(t_format format, va_list *argv, size_t *len)
{
	char	buf[2];

	buf[0] = va_arg(*argv, int);
	buf[1] = '\0';
	format.len -= 1;
	print_buf_with_pad(format, buf, len);
}
