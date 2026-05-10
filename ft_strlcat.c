/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:04:34 by kayoshid          #+#    #+#             */
/*   Updated: 2026/05/10 20:01:24 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (dst_len + i + 1 < size && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int main(void)
// {
// 	// テスト1: 十分なスペースがある場合
// 	char dest1[20] = "Hello";
// 	char *src1 = " World!";
// 	size_t res1 = ft_strlcat(dest1, src1, 20);
// 	printf("Test 1 (Normal):   Result = %zu, Dest = \"%s\"\n", res1, dest1);

// 	// テスト2: スペースが足りない場合
// 	char dest2[10] = "Hello";
// 	char *src2 = " World!";
// 	size_t res2 = ft_strlcat(dest2, src2, 10);
// 	printf("Test 2 (Truncate): Result = %zu, Dest = \"%s\"\n", res2, dest2);

// 	// テスト3: size が dst の長さより小さい場合
// 	char dest3[10] = "Hello";
// 	char *src3 = " World!";
// 	size_t res3 = ft_strlcat(dest3, src3, 3);
// 	printf("Test 3 (Small):    Result = %zu, Dest = \"%s\"\n", res3, dest3);

// 	return (0);
// }
