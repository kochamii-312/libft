/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:00:13 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 07:00:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void bzero(void *s, size_t n)
{
    /*
    s: A pointer to the block of memory to be set to zero.
    n: The number of bytes to be set to zero.
    */
    unsigned char *ptr;
    ptr = (ubsigned char *)s;

    while (n > 0) {
        *ptr = 0;
        ptr++;
        n--;
    }
}
