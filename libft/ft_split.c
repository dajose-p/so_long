/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:09:50 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/05 18:09:53 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

int	word_length(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	free_mem(char **arr, int i)
{
	while (i-- > 0)
		free(arr[i]);
	free(arr);
}

char	**allocate_memory(char const *s, char c, int word_count)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc((word_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] == c)
			j++;
		arr[i] = malloc((word_length(s, c, j) + 1) * sizeof(char));
		if (arr[i] == NULL)
		{
			free_mem(arr, i);
			return (NULL);
		}
		j += word_length(s, c, j);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word_count;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	arr = allocate_memory(s, c, word_count);
	if (arr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < word_count)
	{
		while (s[k] == c)
			k++;
		j = 0;
		while (s[k] != c && s[k] != '\0')
			arr[i][j++] = s[k++];
		arr[i][j] = '\0';
		i++;
	}
	return (arr);
}
