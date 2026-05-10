/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:03:18 by kayoshid          #+#    #+#             */
/*   Updated: 2026/05/10 20:22:48 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = ft_memset(s, 0, n);
}

// int	main()
// {
// 	char	str[] = "Hello, world!";
// 	size_t	n = 5;
// 	printf("%s\n", str);
// 	ft_bzero(str, n);
// 	printf("%s\n", str);
// 	return (0);
// }
