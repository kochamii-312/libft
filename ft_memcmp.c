/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:00:57 by kayoshid          #+#    #+#             */
/*   Updated: 2026/04/25 16:55:54 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

int	memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char p1;
	unsigned char p2;
	
	p1 = (const unsigned char)s1;
	p2 = (const unsigned char)s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (p1 != p2)
			return (p1 - p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}

int main(void)
{
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";
	size_t n = 5;

	int result = memcmp(str1, str2, n);
	if (result == 0)
	{
		printf("The first %zu bytes of str1 and str2 are equal.\n", n);
	}
	else if (result < 0)
	{
		printf("The first %zu bytes of str1 are less than those of str2.\n", n);
	}
	else
	{
		printf("The first %zu bytes of str1 are greater than those of str2.\n", n);
	}
	return 0;
}