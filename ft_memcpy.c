/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:49:17 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 08:49:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *memcpy(void *dst, const void *src, size_t n)
{
    /*
    dst: A pointer to the destination memory area where the content is to be copied.
    src: A pointer to the source memory area from which the content is to be copied.
    n: The number of bytes to copy.
    */
    unsigned char *d;
    const unsigned char *s;
    d = (unsigned char *)dst;
    s = (const unsigned char *)src;

    while (n > 0) {
        *d++ = *s++;
        n--;
    }
    return dst;
}