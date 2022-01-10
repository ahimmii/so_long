/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:06:25 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/07 15:06:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	i;
	long int	num;
	char		*s;

	num = n;
	i = ft_size(num);
	s = (char *) malloc(i + 1);
	if (!s)
		return (0);
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
	}
	if (num == 0)
		s[0] = '0';
	s[i--] = '\0';
	while (num > 0)
	{
		s[i--] = num % 10 + 48;
		num = num / 10;
	}
	return (s);
}
