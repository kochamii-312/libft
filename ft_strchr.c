/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:31:23 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 11:31:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *strchr(const char *s, int c)
{
    /*
    s: A pointer to the null-terminated string to be searched.
    c: The character to be located. The value is passed as an 'int, but the function uses only the lower 8 bits of the value to search for the character in the string.
    */
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    if (c == '\0') {
        return (char *)s;
    }
    return NULL;
}