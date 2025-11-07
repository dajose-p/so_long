/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:23:49 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/02 19:50:13 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(unsigned char *ptr)
{
	if (*ptr == ' ' || *ptr == '\f' || *ptr == '\n' || *ptr == '\r'
		|| *ptr == '\t' || *ptr == '\v')
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int				res;
	int				neg;
	unsigned char	*ptr;

	res = 0;
	neg = 0;
	ptr = (unsigned char *)nptr;
	while (ft_isspace(ptr) == 0)
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			neg = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (res);
		res = 10 * res + (*ptr - '0');
		ptr++;
	}
	if (neg < 0)
		return (-res);
	return (res);
}
