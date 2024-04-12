/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:34:49 by stan              #+#    #+#             */
/*   Updated: 2024/03/16 20:16:02 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (size != 0 && count > INT_MAX / size)
		return (0);
	a = malloc(count * size);
	if (!a)
		return (0);
	ft_bzero(a, (count * size));
	return (a);
}
