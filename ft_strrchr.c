/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:32:26 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 11:32:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *strrchr(const char *s, int c)
{
    /*
    s: A pointer to the null-terminated string to be searched.
    c: The character to be located. The value is passed as an 'int, but the function uses only the lower 8 bits of the value to search for the character in the string.
    */
    const char *last_occurrence = NULL;

    while (*s != '\0') {
        if (*s == (char)c) {
            last_occurrence = s;
        }
        s++;
    }
    if (c == '\0') {
        return (char *)s;
    }
    return (char *)last_occurrence;
}
