/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 05:21:20 by kayoshid          #+#    #+#             */
/*   Updated: 2026/05/08 18:02:08 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digit_count(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	fill_string(char *str, long num, size_t len, int is_negative)
{
	str[len] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return ;
	}
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	if (is_negative)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*str;
	int		is_negative;

	num = n;
	is_negative = n < 0;
	if (is_negative)
		num = -n;
	else
		num = n;
	len = get_digit_count(num);
	if (is_negative)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	fill_string(str, num, len, is_negative);
	return (str);
}
