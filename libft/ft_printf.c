/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 21:11:59 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/12 18:06:20 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_letter(va_list ap, char const letter)
{
	int	i;

	i = 0;
	if (letter == 'c')
		i += ft_printchar(va_arg(ap, int));
	if (letter == 's')
		i += ft_printstr(va_arg(ap, char *));
	if (letter == 'p')
		i += ft_printpointer(va_arg(ap, uintptr_t));
	if (letter == 'd' || letter == 'i')
		i += ft_printnbr(va_arg(ap, int));
	if (letter == 'u')
		i += ft_printnbr_uns(va_arg(ap, unsigned int));
	if (letter == 'x')
		i += ft_printnbr_hex(va_arg(ap, int), 0);
	if (letter == 'X')
		i += ft_printnbr_hex(va_arg(ap, int), 1);
	if (letter == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(char const *last, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, last);
	while (last[i])
	{
		if (last[i] == '%')
		{
			count += check_letter(ap, last[i + 1]);
			i++;
		}
		else
			count += ft_printchar(last[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
