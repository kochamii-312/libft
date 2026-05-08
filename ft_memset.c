/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:04:11 by kayoshid          #+#    #+#             */
/*   Updated: 2026/05/08 19:22:25 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}

// int	main(void)
// {
// 	char	src[] = "Hello World!";
// 	printf("%s\n", src);
// 	// ft_memset(src, 0, 5)とするとヌル文字で埋められる
// 	// ft_memset(src, 1, 5)とするとprintableでない文字となる
// 	char	*res = (char *)ft_memset(src, 0, 5);
// 	printf("%s\n", res);
// 	return (0);
// }
