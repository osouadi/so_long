/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:13:32 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:13:34 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map(t_map *map, t_data *data)
{
	map->character_move = 0;
	map->character_x = 0;
	map->character_y = 0;
	map->colection = 0;
	map->width = 0;
	map->height = 0;
	map->map = 0;
	data->mlx_ptr = 0;
}

size_t	ft_strlen_nl(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static void	ft_free_img(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->character_img)
			mlx_destroy_image(data->mlx_ptr, data->character_img);
		if (data->collection_img)
			mlx_destroy_image(data->mlx_ptr, data->collection_img);
		if (data->exit_img)
			mlx_destroy_image(data->mlx_ptr, data->exit_img);
		if (data->floor_img)
			mlx_destroy_image(data->mlx_ptr, data->floor_img);
		if (data->wall_img)
			mlx_destroy_image(data->mlx_ptr, data->wall_img);
	}
}

static void	ft_free_split(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->height && data->map->height)
	{
		if (data->map->map[i])
			free(data->map->map[i]);
		i++;
	}
	if (data->map->map)
	{
		free(data->map->map);
		data->map->map = NULL;
	}
}

int	ft_close(t_data *data)
{
	ft_free_split(data);
	ft_free_img(data);
	if (data->map)
		free(data->map);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(0);
	return (0);
}
