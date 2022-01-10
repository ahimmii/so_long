/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:09:39 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/12 19:09:41 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define RIGHT 2
# define LEFT 0
# define UP 13
# define DOWN 1

typedef struct s_pos
{
	int	x;
	int	y;

}			t_pos;

struct s_list {
	void	*mlx;
	void	*win;
	void	*img;
	int		com;
	int		x;
	int		i;
	int		e_len;
	int		l_len;
	char	**map;
	t_pos	pos;
}			t_list;

typedef struct s_hero
{
	t_pos	pos;
	char	*img;
	int		ln;
}				t_hero;

void	maps(void);
int		move(void);
int		test(void);
void	ft_putnbr(int n);
t_pos	where_is_my_fucking_player(char **map);
char	*ft_strdup(const char *src);
int		mlx_key(int keycode, void *param);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *destination, const void *source, size_t size);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif
