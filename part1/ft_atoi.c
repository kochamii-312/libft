/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayoshid <kayoshid@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:09:07 by kayoshid          #+#    #+#             */
/*   Updated: 2026/04/29 18:27:19 by kayoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		m;
	long	ans;

	i = 0;
	m = 1;
	ans = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str = "-2147483648")
		return (-2147483648);	
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = m * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	ans = ans * m;
	return (ans);
}

// int	main(void)
// {
// 	char	a[] = " ---+--+1234ab567";
// 	printf("%d", ft_atoi(a));
// 	return (0);
// }
