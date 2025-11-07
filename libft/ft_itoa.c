/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:12:27 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/06 17:42:49 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	*fill_array(char *arr, size_t size, int n_aux, int n)
{
	while (size > 0)
	{
		arr[size - 1] = (n_aux % 10) + '0';
		n_aux = n_aux / 10;
		size--;
	}
	if (n < 0)
		arr[size] = '-';
	return (arr);
}

static void	*mem_alloc(char *arr, size_t len)
{
	arr = malloc((len + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	else
		return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;
	int		n_aux;

	n_aux = n;
	arr = NULL;
	size = nbr_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	arr = mem_alloc(arr, size);
	if (arr == NULL)
		return (NULL);
	if (n < 0)
		n_aux = -n_aux;
	arr[size] = '\0';
	arr = fill_array(arr, size, n_aux, n);
	return (arr);
}
