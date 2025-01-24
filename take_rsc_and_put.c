/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_rsc_and_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:18:50 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:18:52 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_img(t_data *data, void *img)
{
	mlx_destroy_image(data->mlx_ptr, img);
}

static void	ft_free_img3(t_data *data, void *img, void *img2, void *img3)
{
	mlx_destroy_image(data->mlx_ptr, img);
	mlx_destroy_image(data->mlx_ptr, img2);
	mlx_destroy_image(data->mlx_ptr, img3);
}

static int	player_img(t_data *data)
{
	int	width;
	int	height;

	data->character_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/tayf.xpm", &width, &height);
	if (!(data->character_img))
		return (ft_close(data), 0);
	return (0);
}

static int	map_img(t_data *data)
{
	data->wall_img = ft_src_img(data, "./textures/rock_in_water_06.xpm");
	if (!(data->wall_img))
		return (ft_close(data), 0);
	data->floor_img = ft_src_img(data, "./textures/floor.xpm");
	if (!(data->floor_img))
		return (ft_free_img(data, data->wall_img), ft_close(data), 0);
	data->collection_img = ft_src_img(data, "./textures/StaticCoin.xpm");
	if (!(data->collection_img))
		return (ft_free_img(data, data->wall_img),
			ft_free_img(data, data->floor_img), ft_close(data), 0);
	data->exit_img = ft_src_img(data, "./textures/door.xpm");
	if (!(data->collection_img))
	{
		return (ft_free_img3(data, data->floor_img, data->wall_img,
				data->collection_img), ft_close(data), 0);
	}
	return (0);
}

void	coloring_map(t_data *data, int x, int y)
{
	map_img(data);
	player_img(data);
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (data->map->map[y][x] == '1')
				ft_put_to_window(data, x, y, data->wall_img);
			else if (data->map->map[y][x] == '0')
				ft_put_to_window(data, x, y, data->floor_img);
			else if (data->map->map[y][x] == 'C')
				ft_put_to_window(data, x, y, data->collection_img);
			else if (data->map->map[y][x] == 'P')
				ft_put_to_window(data, x, y, data->character_img);
			else if (data->map->map[y][x] == 'E')
				ft_put_to_window(data, x, y, data->exit_img);
			x++;
		}
		y++;
	}
}
