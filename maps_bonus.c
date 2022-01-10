/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:00 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/12 19:06:04 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_0_1_p(int x, int y, int width, int height)
{
	if (t_list.map[y][x] == '0')
	{
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/ter.xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, x * 100, y * 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
	}
	if (t_list.map[y][x] == '1')
	{
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/a(1).xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, x * 100, y * 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
	}
	if (t_list.map[y][x] == 'P')
	{
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/ter.xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, x * 100, y * 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
	}
}

void	check_c_e_m(int x, int y, int height, int width)
{
	if (t_list.map[y][x] == 'C')
	{
		t_list.com++;
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/C(1).xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, x * 100, y * 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
	}
	if (t_list.map[y][x] == 'E')
	{
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/E(1).xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, x * 100, y * 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
	}
	if (t_list.map[y][x] == 'M')
	{
		t_list.img = mlx_xpm_file_to_image(t_list.mlx,
				"./img_xpm/O(1).xpm", &width, &height);
		mlx_put_image_to_window(t_list.mlx, t_list.win,
			t_list.img, x * 100, y * 100);
		mlx_destroy_image(t_list.mlx, t_list.img);
	}
}

void	maps(void)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = 0;
	height = 0;
	y = 0;
	t_list.com = 0;
	while (t_list.map[y])
	{
		x = 0;
		while (t_list.map[y][x])
		{
			check_0_1_p(x, y, width, height);
			check_c_e_m(x, y, width, height);
			x++;
		}
		y++;
	}
}
