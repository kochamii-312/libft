/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:17:02 by kayoshid          #+#    #+#             */
/*   Updated: 2026/04/25 16:27:17 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "Hello, World!";
// 	int c = 'o';
// 	size_t n = 5;

// 	char *result = ft_memchr(str, c, n);
// 	if (result != NULL)
// 	{
// 		printf("Character '%c' found at position: %ld\n", c, result - str);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the first %zu bytes.\n", c, n);
// 	}
// 	return 0;
// }
