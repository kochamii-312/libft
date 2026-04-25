/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:21:37 by marvin            #+#    #+#             */
/*   Updated: 2026/04/25 09:21:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void strlcat(char *dst, const char *src)
{
    /*
    dst: A pointer to the destination buffer where the content is to be appended.
    src: A pointer to the null-terminated string to be appended.
    */
    int dst_len;
    int i;

    dst_len = strlen(dst);
    i = 0;

    while (src[i] != '\0') {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
}
