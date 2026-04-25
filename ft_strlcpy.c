/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 08:59:26 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 08:59:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void strlcpy(char *dst, const char *src)
{
    /*
    dst: A pointer to the destination buffer where the content is to be copied.
    src: A pointer to the null-terminated string to be copied.
    */
    int i;
    i = 0;

    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}