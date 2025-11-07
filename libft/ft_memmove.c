/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:34:53 by danjose-          #+#    #+#             */
/*   Updated: 2025/09/30 12:45:36 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*aux;
	char	*ch_dest;

	ch_dest = (char *)dest;
	aux = (char *)src;
	if (aux < ch_dest)
	{
		while (n-- > 0)
		{
			ch_dest[n] = aux[n];
		}
	}
	else
		ft_memcpy(ch_dest, aux, n);
	return ((void *)ch_dest);
}
