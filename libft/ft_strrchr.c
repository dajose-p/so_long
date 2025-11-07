/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:51:41 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/01 19:10:22 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	const char		*aux;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	aux = NULL;
	while (s[i])
	{
		if (s[i] == uc)
			aux = &s[i];
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return ((char *)aux);
}
