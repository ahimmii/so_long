/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:06:13 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/12 19:06:19 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	movment(char *img[22])
{
	int			width;
	int			height;
	static int	i = 0;
	char		*str;

	width = 0;
	height = 0;
	if (i == 20)
		i = 0;
	t_list.img = mlx_xpm_file_to_image(t_list.mlx, img[i++], &width, &height);
	mlx_put_image_to_window(t_list.mlx, t_list.win,
		t_list.img, t_list.pos.x, t_list.pos.y);
	mlx_destroy_image(t_list.mlx, t_list.img);
	str = ft_itoa(t_list.x);
	str = ft_strjoin("Movment : ", str);
	mlx_string_put(t_list.mlx, t_list.win, 5, 5, 0x00000000, str);
	free(str);
}

int	move(void)
{
	static char	*img[22] = {"./img_xpm/(1).xpm", "./img_xpm/(2).xpm",
		"./img_xpm/(3).xpm", "./img_xpm/(3).xpm",
		"./img_xpm/(4).xpm", "./img_xpm/(4).xpm",
		"./img_xpm/(5).xpm", "./img_xpm/(6).xpm",
		"./img_xpm/(7).xpm", "./img_xpm/(7).xpm",
		"./img_xpm/(7).xpm", "./img_xpm/(7).xpm",
		"./img_xpm/(7).xpm", "./img_xpm/(7).xpm",
		"./img_xpm/(6).xpm", "./img_xpm/(5).xpm",
		"./img_xpm/(4).xpm", "./img_xpm/(3).xpm",
		"./img_xpm/(2).xpm", "./img_xpm/(1).xpm",
		"./img_xpm/(1).xpm", "./img_xpm/(1).xpm"};

	t_list.pos = where_is_my_fucking_player(t_list.map);
	t_list.pos.x *= 100;
	t_list.pos.y *= 100;
	maps();
	movment(img);
	return (0);
}
