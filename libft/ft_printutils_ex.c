/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils_ex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 01:44:12 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/12 17:34:50 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (i += ft_printstr("(null)"));
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	count_num_hex(long long n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

static void	ft_putnbr_hex(long long ln, int up)
{
	static char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};
	static char	may[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F'};

	if (ln < 0)
	{
		ft_putchar_fd('-', 1);
		ln = -ln;
	}
	if ((ln / 16) > 0)
		ft_putnbr_hex(ln / 16, up);
	if (up == 0)
		ft_putchar_fd(hex[ln % 16], 1);
	else
		ft_putchar_fd(may[ln % 16], 1);
}

int	ft_printnbr_hex(long long nl, int up)
{
	int	count;

	count = 0;
	if (nl < 0)
	{
		nl = -nl;
		nl = UINT_MAX - (nl - 1);
	}
	ft_putnbr_hex(nl, up);
	if (nl == 0)
		return (1);
	count += count_num_hex(nl);
	return (count);
}
