/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:25:49 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 21:27:51 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrev(char *s, size_t n)
{
	char	*p2;
	char	tmp;

	p2 = s + n - 1;
	while (s < p2)
	{
		tmp = *s;
		*s++ = *p2;
		*p2-- = tmp;
	}
	return (s);
}
