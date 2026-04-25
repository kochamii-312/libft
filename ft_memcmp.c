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
	unsigned int p1;
	unsigned int p2;
	
	p1 = (const unsigned int)s1;
	p2 = (const unsigned int)s2;
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
