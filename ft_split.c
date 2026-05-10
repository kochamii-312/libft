/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 05:21:53 by kayoshid          #+#    #+#             */
/*   Updated: 2026/05/09 15:00:12 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_length(char const *s, size_t start, char c)
{
	size_t	length;

	length = 0;
	while (s[start + length] != '\0' && s[start + length] != c)
		length++;
	return (length);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			i += word_length(s, i, c);
		}
	}
	return (count);
}

static int	fill_result(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		len = word_length(s, i, c);
		result[j] = ft_substr(s, i, len);
		if (result[j++] == NULL)
			return (0);
		i += len;
	}
	result[j] = NULL;
	return (1);
}

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (!fill_result(result, s, c))
	{
		free_split(result);
		return (NULL);
	}
	return (result);
}
