/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:06:25 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/11 15:06:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_tst1(int p)
{
	int	i;
	int	j;

	i = -1;
	while (t_list.map[++i])
	{
		j = -1;
		while (t_list.map[i][++j])
		{
			if (t_list.map[i][j] != '1' && t_list.map[i][j] != 'C' &&
					t_list.map[i][j] != '0' && t_list.map[i][j] != 'P'
					&& t_list.map[i][j] != 'E' && t_list.map[i][j] != 'M')
				return (perror("Missing '1'or'C'or'0'or'P'or'E'or'P'"), 0);
			if (t_list.map[i][j] == 'P')
				if (++p > 1)
					return (perror("you have to much players"), 0);
			if (t_list.map[i][j] == 'E')
				++t_list.e_len;
			if (t_list.map[i][j] == 'C')
				++t_list.l_len;
		}
	}
	if (p == 0)
		return (perror("You didn't choose a place Player"), 0);
	return (1);
}

int	test_tst2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (t_list.map[0][j])
	{
		if (t_list.map[0][j] != '1')
			return (perror("The first Or last line is not all 1"), 0);
		j++;
	}
	while (t_list.map[i])
		i++;
	i--;
	j = -1;
	while (t_list.map[i][++j])
		if (t_list.map[i][j] != '1')
			return (perror("much players Or your add element not exist"), 0);
	i = 0;
	j = ft_strlen(t_list.map[0]);
	while (t_list.map[++i])
		if (t_list.map[i][0] != '1'
			|| t_list.map[i][j - 1] != '1')
			return (perror("Error\nthe map must be closed by walls '1'"), 0);
	return (1);
}

int	test(void)
{
	int	i;
	int	p;
	int	x;

	i = 0;
	x = 0;
	p = 0;
	if (test_tst1(p) == 0)
		return (perror("error"), 0);
	if (test_tst2() == 0)
		return (perror("error"), 0);
	i = 0;
	x = ft_strlen(t_list.map[i]);
	while (t_list.map[i])
	{
		if (x != (int)ft_strlen(t_list.map[i++]))
			return (perror("extra character in one of the lines"), 0);
	}
	if (t_list.e_len == 0 || t_list.l_len == 0)
	{
		return (perror("Missing C Or E"), 0);
	}
	return (1);
}
