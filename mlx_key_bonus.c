/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:35 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/12 19:06:37 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	right(int keycode, t_pos player_t_pos, int width, int height)
{
	if (keycode == RIGHT)
	{
		if (t_list.map[player_t_pos.y][player_t_pos.x + 1] != '1'
		&& (t_list.map[player_t_pos.y][player_t_pos.x + 1] != 'E'
		|| t_list.com == 0))
		{
			if (t_list.map[player_t_pos.y][player_t_pos.x + 1] == 'E')
				write(1, "You Win\n", 8);
			if (t_list.map[player_t_pos.y][player_t_pos.x + 1] == 'M')
				write(1, "Your death\n", 11);
			if (t_list.map[player_t_pos.y][player_t_pos.x + 1] == 'E'
				|| t_list.map[player_t_pos.y][player_t_pos.x + 1] == 'M')
				exit(0);
			maps();
			t_list.map[player_t_pos.y][player_t_pos.x + 1] = 'P';
			t_list.map[player_t_pos.y][player_t_pos.x] = '0';
			t_list.img = mlx_xpm_file_to_image(t_list.mlx,
					"./img_xpm/(1).xpm", &width, &height);
			mlx_put_image_to_window(t_list.mlx, t_list.win,
				t_list.img, t_list.pos.x += 100, t_list.pos.y);
			mlx_destroy_image(t_list.mlx, t_list.img);
			t_list.x++;
		}
	}
}

void	down(int keycode, t_pos player_t_pos, int width, int height)
{
	if (keycode != DOWN)
		return ;
	if (t_list.map[player_t_pos.y + 1][player_t_pos.x] != '1'
		&& (t_list.map[player_t_pos.y + 1][player_t_pos.x] != 'E'
		|| t_list.com == 0))
	{
		if (t_list.map[player_t_pos.y + 1][player_t_pos.x] == 'E')
			write(1, "You Win\n", 8);
		if (t_list.map[player_t_pos.y + 1][player_t_pos.x] == 'M')
			write(1, "Your death\n", 11);
		if (t_list.map[player_t_pos.y + 1][player_t_pos.x] == 'M'
			|| t_list.map[player_t_pos.y + 1][player_t_pos.x] == 'E')
			exit(0);
		maps();
		t_list.map[player_t_pos.y][player_t_pos.x] = '0';
		t_list.map[player_t_pos.y + 1][player_t_pos.x] = 'P';
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/(1).xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, t_list.pos.x, t_list.pos.y += 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
		t_list.x++;
	}
}

void	up(int keycode, t_pos player_t_pos, int width, int height)
{
	if (keycode == UP)
	{
		if (t_list.map[player_t_pos.y - 1][player_t_pos.x] != '1'
		&& (t_list.map[player_t_pos.y - 1][player_t_pos.x] != 'E'
		|| t_list.com == 0))
		{
			if (t_list.map[player_t_pos.y - 1][player_t_pos.x] == 'E')
				write(1, "You Win\n", 8);
			if (t_list.map[player_t_pos.y - 1][player_t_pos.x] == 'M')
				write(1, "Your death\n", 11);
			if (t_list.map[player_t_pos.y - 1][player_t_pos.x] == 'E'
				|| t_list.map[player_t_pos.y - 1][player_t_pos.x] == 'M')
				exit(0);
			maps();
			t_list.map[player_t_pos.y - 1][player_t_pos.x] = 'P';
			t_list.map[player_t_pos.y][player_t_pos.x] = '0';
			t_list.img = mlx_xpm_file_to_image(t_list.mlx,
					"./img_xpm/(1).xpm", &width, &height);
			mlx_put_image_to_window(t_list.mlx, t_list.win,
				t_list.img, t_list.pos.x, t_list.pos.y -= 100);
			mlx_destroy_image(t_list.mlx, t_list.img);
			t_list.x++;
		}
	}
}

void	left(int keycode, t_pos player_t_pos, int width, int height)
{
	if (keycode == LEFT)
	{
		if (t_list.map[player_t_pos.y][player_t_pos.x - 1] != '1'
		&& (t_list.map[player_t_pos.y][player_t_pos.x - 1] != 'E'
		|| t_list.com == 0))
		{
			if (t_list.map[player_t_pos.y][player_t_pos.x - 1] == 'E')
				write(1, "You Win\n", 8);
			if (t_list.map[player_t_pos.y][player_t_pos.x - 1] == 'M')
				write(1, "Your death\n", 11);
			if (t_list.map[player_t_pos.y][player_t_pos.x - 1] == 'E'
				|| t_list.map[player_t_pos.y][player_t_pos.x - 1] == 'M')
				exit(0);
			maps();
			t_list.map[player_t_pos.y][player_t_pos.x - 1] = 'P';
			t_list.map[player_t_pos.y][player_t_pos.x] = '0';
			t_list.img = mlx_xpm_file_to_image(t_list.mlx,
					"./img_xpm/(1).xpm", &width, &height);
			mlx_put_image_to_window(t_list.mlx, t_list.win,
				t_list.img, t_list.pos.x -= 100, t_list.pos.y);
			mlx_destroy_image(t_list.mlx, t_list.img);
			t_list.x++;
		}
	}
}

int	mlx_key(int keycode, void *param)
{
	int		width;
	int		height;
	t_pos	player_t_pos;

	param += 0;
	width = 0;
	height = 0;
	player_t_pos = where_is_my_fucking_player(t_list.map);
	right(keycode, player_t_pos, width, height);
	down(keycode, player_t_pos, width, height);
	up(keycode, player_t_pos, width, height);
	left(keycode, player_t_pos, width, height);
	if (keycode == 53)
	{
		mlx_destroy_window(t_list.mlx, t_list.win);
		exit(0);
	}
	write(1, "Movment : ", 10);
	ft_putnbr(t_list.x);
	write(1, "\n", 1);
	return (0);
}
