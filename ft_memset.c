/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 06:27:15 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 06:27:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *memset(void *b, int c, size_t len)
{
    /*
    b: A pointer to the block of memory to fill.
    c: The value to be set. The value is passed as a 'int, but the function uses only the lower 8 bits of the value to fill the memory block.
    len: The number of bytes to be set to the value.
    */
    unsigned char *ptr;
    ptr = (unsigned char *)b;
    
    while (len > 0) {
        *ptr = (unsigned char)c;
        ptr++;
        len--;
    }
    return b;
}
