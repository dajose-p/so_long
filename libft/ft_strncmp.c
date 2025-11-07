/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:16:49 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/01 20:17:10 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while ((*us1 || *us2) && (i < n))
	{
		if (*us1 == *us2)
		{
			s1++;
			s2++;
			n--;
			return (ft_strncmp(s1, s2, n));
		}
		if (*us1 < *us2)
			return (-1);
		if (*us1 > *us2)
			return (1);
		i++;
	}
	return (0);
}
