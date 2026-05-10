/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:04:05 by kayoshid          #+#    #+#             */
/*   Updated: 2026/05/09 14:48:41 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n-- > 0)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n-- > 0)
			*(--d) = *(--s);
	}
	return (dest);
}

// int main() {
//     // 1. 重なりがないケース (十分な領域を確保)
//     char buf1[20] = "Hello World";
//     ft_memmove(buf1 + 6, "Hello", 5); // "Hello" を "World" の位置へコピー
//     printf("Test 1 (No overlap): %s\n", buf1); // 期待値: HelloHello

//     // 2. 重なりがあるケース (前方へのシフト)
//     char buf2[] = "abcdefghij";
//     ft_memmove(buf2, buf2 + 2, 5); // "cdefg" を "ab" の位置へ
//     printf("Test 2 (Overlap forward): %s\n", buf2); // 期待値: cdefgfghij

//     // 3. 重なりがあるケース (後方へのシフト)
//     char buf3[] = "abcdefghij";
//     ft_memmove(buf3 + 2, buf3, 5); // "abcde" を "cdefg" の位置へ
//     printf("Test 3 (Overlap backward): %s\n", buf3); // 期待値: ababcdehij

//     return (0);
// }