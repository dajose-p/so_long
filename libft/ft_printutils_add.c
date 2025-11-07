/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:45:30 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/12 18:38:00 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_ptr(uintptr_t n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static void	ft_putptr(uintptr_t ptr)
{
	static char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

	if ((ptr / 16) > 0)
		ft_putptr(ptr / 16);
	ft_putchar_fd(hex[ptr % 16], 1);
}

int	ft_printpointer(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += ft_printstr("(nil)");
		return (count);
	}
	count += ft_printstr("0x");
	ft_putptr(ptr);
	count += count_ptr(ptr);
	return (count);
}
