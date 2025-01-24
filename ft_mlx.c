/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:14:18 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:14:20 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_collect(int x, int y, t_data *data, int key)
{
	ft_put_img(data->floor_img, x, y, data);
	ft_put_img(data->floor_img, data->map->character_x,
		data->map->character_y, data);
	if (key == RIGHT || key == D)
		ft_put_img(data->character_img, x, y, data);
	else if (key == LEFT || key == A)
		ft_put_img(data->character_img, x, y, data);
	else if (key == UP || key == W)
		ft_put_img(data->character_img, x, y, data);
	else
		ft_put_img(data->character_img, x, y, data);
	data->map->map[y][x] = '0';
	data->map->colection--;
}

static int	ft_move(int x, int y, t_data *data, int key)
{
	if (data->map->map[y][x] == '1')
		return (1);
	else if (data->map->map[y][x] == 'E' && data->map->colection != 0)
		return (1);
	else if (data->map->map[y][x] == 'E' && data->map->colection == 0)
		return (write(1, "YOU WON\n", 9), ft_close(data), 0);
	else if (data->map->map[y][x] == '0')
	{
		ft_put_img(data->floor_img, data->map->character_x,
			data->map->character_y, data);
		if (key == RIGHT || key == D)
			ft_put_img(data->character_img, x, y, data);
		else if (key == LEFT || key == A)
			ft_put_img(data->character_img, x, y, data);
		else if (key == UP || key == W)
			ft_put_img(data->character_img, x, y, data);
		else
			ft_put_img(data->character_img, x, y, data);
	}
	else if (data->map->map[y][x] == 'C')
		ft_move_collect(x, y, data, key);
	else if (data->map->map[y][x] == 'B')
		return (write(1, "YOU LOST\n", 9), ft_close(data), 0);
	return (data->map->character_x = x, data->map->character_y = y,
		data->map->character_move += 1, 1);
}

static int	ft_key(int key, t_data *data)
{
	int	x;
	int	y;

	x = data->map->character_x;
	y = data->map->character_y;
	data->map->map[y][x] = '0';
	if (key == ESC)
		return (write(1, "YOU EXITED\n", 11), ft_close(data), 1);
	else if ((key == UP || key == W))
		return (ft_move(x, y - 1, data, key),
			ft_putnbr_n(data->map->character_move), 1);
	else if ((key == RIGHT || key == D))
		return (ft_move(x + 1, y, data, key),
			ft_putnbr_n(data->map->character_move), 1);
	else if ((key == LEFT || key == A))
		return (ft_move(x - 1, y, data, key),
			ft_putnbr_n(data->map->character_move), 1);
	else if ((key == DOWN || key == S))
		return (ft_move(x, y + 1, data, key),
			ft_putnbr_n(data->map->character_move), 1);
	return (0);
}

int	ft_mlx(t_data *data)
{
	int	win_h;
	int	win_w;

	win_h = data->map->height * SIZE;
	win_w = data->map->width * SIZE;
	if (win_w > 3200 || win_h > 1720)
		return (write(2, "ERROR\nSIZE\n", 11), ft_close(data), 0);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == (void *)0)
		return (write(2, "ERROR\nMLX\n", 10), ft_close(data), 0);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			win_w, win_h, "./so_long");
	if (data->win_ptr == (void *)0)
		return (write(2, "ERROR\nMLX\n", 10), ft_close(data), 0);
	coloring_map(data, 0, 0);
	mlx_key_hook(data->win_ptr, ft_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}
