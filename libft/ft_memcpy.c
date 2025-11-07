/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:12:02 by danjose-          #+#    #+#             */
/*   Updated: 2025/09/30 12:31:48 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*ch_src;
	char		*ch_dest;

	ch_src = (const char *)src;
	ch_dest = (char *)dest;
	i = 0;
	if (!src && !dest)
		return (dest);
	while (i < n)
	{
		ch_dest[i] = ch_src[i];
		i++;
	}
	return ((void *)ch_dest);
}
