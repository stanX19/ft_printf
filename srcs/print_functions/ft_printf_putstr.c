/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:39:26 by stan              #+#    #+#             */
/*   Updated: 2024/03/09 16:59:27 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_putstr(const char *str, size_t *len)
{
	size_t	idx;

	idx = ft_strlen(str);
	*len += idx;
	write(1, str, idx);
}

void	ft_printf_putnstr(const char *str, int n, size_t *len)
{
	if (n <= 0)
		return ;
	*len += n;
	write(1, str, n);
}
