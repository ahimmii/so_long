/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:06:25 by ahimmi            #+#    #+#             */
/*   Updated: 2021/11/07 15:06:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*s;

	if (!s1 || !s2)
		return (0);
	i = 0;
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (0);
	ft_memmove(s, s1, ft_strlen(s1));
	ft_memmove(s + ft_strlen(s1), s2, ft_strlen(s2));
	s[ft_strlen(s1)+ft_strlen(s2)] = '\0';
	free((void *) s2);
	return (s);
}
