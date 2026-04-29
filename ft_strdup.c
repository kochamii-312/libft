/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 05:21:07 by kayoshid          #+#    #+#             */
/*   Updated: 2026/04/30 05:21:09 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    char *dup;
    size_t len;

    dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    if (dup == NULL)
        return (NULL);
    len = 0;
    while (s[len] != '\0')
    {
        dup[len] = s[len];
        len++;
    }
    dup[len] = '\0';
    return (dup);
}
