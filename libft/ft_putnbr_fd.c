/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 22:25:49 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/05 23:10:38 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	ln;

	c = 0;
	ln = (long)n;
	if (ln < 0)
	{
		ln = -ln;
		ft_putchar_fd('-', fd);
	}
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	c = (ln % 10) + '0';
	ft_putchar_fd(c, fd);
}
