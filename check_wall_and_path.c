/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_and_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:12:28 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:12:30 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clear_cpy(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->cpy[i])
	{
		free(data->map->cpy[i]);
		i++;
	}
	free(data->map->cpy);
}

static int	ft_fill(char **str, int x, int y)
{
	int	nmbc;

	if (str[y][x] == 'E')
		return (str[y][x] = '1', 1);
	nmbc = 0;
	if (str[y][x] == '1')
		return (0);
	else if (str[y][x] == 'C')
		nmbc++;
	str[y][x] = '1';
	nmbc += ft_fill(str, x, y - 1);
	nmbc += ft_fill(str, x - 1, y);
	nmbc += ft_fill(str, x, y + 1);
	nmbc += ft_fill(str, x + 1, y);
	return (nmbc);
}

static int	check_tow_side_wall(t_data *data, int width)
{
	int	h;

	h = 1;
	while (h < data->map->height)
	{
		if (data->map->map[h][0] != '1')
			return (0);
		else if (data->map->map[h][width - 1] != '1')
			return (0);
		h++;
	}
	return (1);
}

int	ft_validate_walls(t_data *data, int h, int width)
{
	int	w;

	w = 0;
	while (data->map->map[0][w] != '\n' && data->map->map[0][w])
	{
		if (data->map->map[0][w] != '1')
			return (0);
		w++;
	}
	w = 0;
	h = data->map->height - 1;
	while (data->map->map[h][w] != '\n' && data->map->map[h][w])
	{
		if (data->map->map[h][w] != '1')
			return (0);
		w++;
	}
	if (!(check_tow_side_wall(data, width)))
		return (0);
	return (1);
}

int	ft_valid_path(t_data *data, int nmbc)
{
	int	width;
	int	height;
	int	valide;
	int	i;

	width = data->map->width;
	height = data->map->height;
	data->map->cpy = (char **)malloc((height + 1) * sizeof(char *));
	if (!data->map->cpy)
		return (0);
	i = 0;
	while (i < height)
	{
		data->map->cpy[i] = ft_strdup(data->map->map[i]);
		if (!data->map->cpy)
			return (ft_clear_cpy(data), 0);
		i++;
	}
	data->map->cpy[i] = 0;
	valide = ft_fill(data->map->cpy, data->map->character_x,
			data->map->character_y);
	if (valide != nmbc + 1)
		return (ft_clear_cpy(data), 0);
	return (ft_clear_cpy(data), 1);
}
