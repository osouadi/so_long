/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:17:41 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/04 20:17:43 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_enmy(t_data *data, int x, int y)
{
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map[y][x] == '0' && (data->map->character_x != x
				|| data->map->character_y != y))
				ft_put_to_window(data, x, y, data->floor_img);
			else if (data->map->map[y][x] == 'B')
				ft_put_to_window(data, x, y, data->enmy_img);
			x++;
		}
		y++;
	}
}

static int	ft_enmy_move(t_data *data, int char_x, int char_y)
{
	static int	dir;
	int			i;
	int			j;

	i = 0;
	while (data->map->map[i] != NULL)
	{
		j = 0;
		while (data->map->map[i][j] && data->map->map[i][j] != '\n')
		{
			ft_check(data, &j, &i, &dir);
			if (data->map->map[i][j] == 'B' && data->map->map[i][j - 1]
					&& (char_x == j && char_y == i))
				return (write(1, "you are lost\n", 13), ft_close(data), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_get_frames(t_data *data)
{
	static int	cur;

	if (cur == 5)
		cur = 0;
	if (cur == 0)
		ft_put_img(data->character1, data->map->character_x,
			data->map->character_y, data);
	else if (cur == 1)
		ft_put_img(data->character2, data->map->character_x,
			data->map->character_y, data);
	else if (cur == 2)
		ft_put_img(data->character_img, data->map->character_x,
			data->map->character_y, data);
	else if (cur == 3)
		ft_put_img(data->character1, data->map->character_x,
			data->map->character_y, data);
	else if (cur == 4)
		ft_put_img(data->character2, data->map->character_x,
			data->map->character_y, data);
	else if (cur == 5)
		ft_put_img(data->character_img, data->map->character_x,
			data->map->character_y, data);
	cur++;
	return ;
}

int	ft_animation(t_data *data)
{
	static int	i;
	int			anim_speed;
	int			enmy_speed;

	anim_speed = 6950;
	enmy_speed = 50000;
	if (i % anim_speed == 0)
	{
		ft_key(0, data);
		ft_get_frames(data);
	}
	if (i % enmy_speed == 0)
		ft_enmy_move(data, data->map->character_x, data->map->character_y);
	if (i == anim_speed * 1000)
		i = 1;
	i++;
	return (0);
}

void	ft_enmy_img(t_data *data, int x, int y)
{
	data->map->enmy_x = x;
	data->map->enmy_y = y;
}
