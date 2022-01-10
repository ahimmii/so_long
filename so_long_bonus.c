/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:06:25 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/11 15:06:28 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_pos	where_is_my_fucking_obj(char **map)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

t_pos	where_is_my_fucking_player(char **map)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

int	map_parsing(char *filename)
{
	char	*line;
	char	*tmp;
	int		nb;

	line = malloc(2048);
	nb = read(open(filename, O_RDONLY), line, 2048);
	if (nb == 0 || nb < 0)
		return (perror("This file does not exist or file is void"), 0);
	line[nb] = 0;
	tmp = ft_strdup(line);
	if (tmp[0] == '\0')
		return (perror("file is NULL"), 0);
	free(line);
	t_list.map = ft_split(tmp, '\n');
	free(tmp);
	return (test());
}

int	exits(int keycode, void *param)
{
	exit(0);
}

int	main(int ac, char **av)
{
	t_pos	win;

	if (ac == 2)
	{
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		{
			perror("you must be file .ber");
			exit(1);
		}
		if (map_parsing(av[1]) == 0)
			return (-1);
		t_list.mlx = mlx_init();
		win.y = ft_strlen(t_list.map[1]) * 100;
		win.x = 0;
		while (t_list.map[win.x])
			win.x++;
		win.x *= 100;
		t_list.win = mlx_new_window(t_list.mlx, win.y, win.x, "So long 42");
		maps();
		mlx_loop_hook(t_list.mlx, &move, &t_list);
		mlx_hook(t_list.win, 17, 0, exits, &t_list);
		mlx_hook(t_list.win, 2, 0, mlx_key, &t_list);
		mlx_loop(t_list.mlx);
	}
}
