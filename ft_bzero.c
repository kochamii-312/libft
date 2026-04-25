/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:03:18 by kayoshid          #+#    #+#             */
/*   Updated: 2026/04/25 16:26:54 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

// int main(void)
// {
// 	char str[] = "Hello, World!";
// 	size_t n = 5;

// 	printf("Before ft_bzero: %s\n", str);
// 	ft_bzero(str, n);
// 	printf("After ft_bzero: %s\n", str);
// 	return 0;
// }