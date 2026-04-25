/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 11:45:31 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 11:45:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
    /*
    s1: A pointer to the first null-terminated string to be compared.
    s2: A pointer to the second null-terminated string to be compared.
    n: The maximum number of characters to compare.
    */
    size_t i;

    i = 0;
    while (i < n) {
        if (s1[i] != s2[i]) {
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        }
        if (s1[i] == '\0') {
            return 0;
        }
        i++;
    }
    return 0;
}
