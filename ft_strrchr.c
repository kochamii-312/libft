/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:06:10 by kayoshid          #+#    #+#             */
/*   Updated: 2026/04/30 04:29:17 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_occurrence);
}

// int	main()
// {
// 	char	str[] = "Hello, World, World!";
// 	char	*result;
// 	int	target = 'W';

// 	result = ft_strrchr(str, target);
// 	printf("%s\n", result);
// 	return (0);
// }
