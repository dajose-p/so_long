/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 21:07:01 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/02 19:21:18 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	*ubig;
	unsigned char	*ulittle;

	i = 0;
	j = 0;
	ubig = (unsigned char *)big;
	ulittle = (unsigned char *)little;
	if (*ulittle == '\0')
		return ((char *)ubig);
	while (ubig[i] && i < len)
	{
		while (ubig[i + j] == ulittle[j] && ulittle[j] && i + j < len)
			j++;
		if (ulittle[j] == '\0')
			return ((char *)&ubig[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
