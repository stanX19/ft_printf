/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:39:33 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:39:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	ft_printf_putchar(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_printf_putnchar(char c, int n, size_t *len)
{
	if (n > 0)
		*len += n;
	while (n-- > 0)
		write(1, &c, 1);
}
