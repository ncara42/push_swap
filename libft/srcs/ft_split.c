/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 05:40:31 by ncaravac          #+#    #+#             */
/*   Updated: 2026/01/06 21:15:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

char	*word_dup(char const *s, size_t start, size_t end)
{
	char	*word;
	size_t	size;
	size_t	index;

	size = end - start;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	index = 0;
	while (start < end)
		word[index++] = s[start++];
	word[index] = '\0';
	return (word);
}

char	**cleaner(char **arr, size_t pos)
{
	while (pos > 0)
		free(arr[--pos]);
	free(arr);
	return (NULL);
}

char	**set_size(char const *s, char c, size_t words, char **arr)
{
	size_t	pos;
	size_t	i;
	size_t	j;

	pos = 0;
	i = 0;
	while (pos < words)
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		arr[pos] = word_dup(s, j, i);
		if (!arr[pos])
			return (cleaner(arr, pos));
		pos++;
	}
	arr[pos] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	if (!s || !*s)
		return (NULL);
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = set_size(s, c, words, arr);
	if (!arr)
		return (NULL);
	return (arr);
}
