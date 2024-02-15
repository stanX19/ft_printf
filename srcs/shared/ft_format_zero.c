/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/02/15 18:25:48 by stan              #+#    #+#             */
/*   Updated: 2024/02/15 18:25:48 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

void	format_zero(t_format *format, long long int val)
{
	format->precicion = format->len;
	format->len = 0;
	if (val < 0)
		format->precicion -= 1;
}
