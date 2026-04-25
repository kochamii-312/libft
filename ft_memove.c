/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 07:25:29 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 07:25:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *memove(void *dst, const void *src, size_t len)
{
    /*
    dst: A pointer to the destination memory area where the content is to be copied.
    src: A pointer to the source memory area from which the content is to be copied.
    len: The number of bytes to copy.
    */
    unsigned char *d;
    const unsigned char *s;
    d = (unsigned char *)dst;
    s = (const unsigned char *)src;

    if (d == s || len == 0) {
        return dst;
    }

    if (d < s) {
        while (len > 0) {
            *d++ = *s++;
            len--;
        }
    } else {
        d += len;
        s += len;
        while (len > 0) {
            *(d + len) = *(s + len);
            len--;
        }
    }
    return dst;
}
