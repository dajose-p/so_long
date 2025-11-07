/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:42:45 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/12 17:45:09 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(long long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int			count;
	long long	nl;

	nl = (long long)n;
	count = 0;
	ft_putnbr_fd(n, 1);
	if (nl == 0)
		return (1);
	if (nl < 0)
	{
		nl = -nl;
		count++;
	}
	count += count_num(nl);
	return (count);
}

int	ft_printnbr_uns(unsigned int n)
{
	int		count;
	char	*num;

	count = 0;
	num = ft_uitoa(n);
	count += ft_printstr(num);
	free(num);
	return (count);
}
