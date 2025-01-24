/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:15:26 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/04 20:15:29 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_cheack_chars(t_data *data, char *str)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->map->height)
	{
		w = 0;
		while (data->map->map[h][w] != '\n' && data->map->map[h][w])
		{
			if (ft_strchr(str, data->map->map[h][w]))
			{
				if (data->map->map[h][w] == 'P')
				{
					data->map->character_x = w;
					data->map->character_y = h;
				}
				w++;
			}
			else
				return (0);
		}
		h++;
	}
	return (1);
}

static int	ft_check_char(t_data *data, char c, int count)
{
	int	h;
	int	w;

	h = 0;
	count = 0;
	while (h < data->map->height)
	{
		w = 0;
		while (data->map->map[h][w])
		{
			if (data->map->map[h][w] == c)
				count++;
			w++;
		}
		h++;
	}
	if (c == 'P' && count != 1)
		return (0);
	else if (c == 'E' && count != 1)
		return (0);
	else if (c == 'C' && count < 1)
		return (0);
	if (c == 'B')
		return (data->map->enmy_x = w, data->map->enmy_y = h);
	return (count);
}

static int	ft_message_error(t_data *data)
{
	int	count;

	count = 0;
	if (!(ft_cheack_chars(data, "01CEPB")))
		return (write(2, "ERROR\n INVALID_CHARS\n", 21),
			ft_close(data), 0);
	if (!(ft_check_char(data, 'P', count)))
		return (write(2, "ERROR\n IT MUST BE ONE PLAYER\n", 29),
			ft_close(data), 0);
	else if (!(ft_check_char(data, 'E', count)))
		return (write(2, "ERROR\n IT MUST BE ONE EXIT\n", 27),
			ft_close(data), 0);
	if (!(ft_check_char(data, 'C', count)))
		return (write(2, "ERROR\n THE N OF COLLECT AT LEAST 1\n", 35),
			ft_close(data), 0);
	if (!(ft_valid_path(data, ft_check_char(data, 'C', count))))
		return (write(2, "ERROR\n INVALIDE PATH\n", 21),
			ft_close(data), 0);
	data->map->enmy = ft_check_char(data, 'B', count);
	return (ft_check_char(data, 'C', count));
}

int	ft_valide(t_data *data)
{
	int		h;
	size_t	width;

	h = 0;
	width = ft_strlen_nl(data->map->map[0]);
	if (!width || width < 0)
		return (write(2, "ERROR\n IN WIDTH OF THE MP\n", 26),
			ft_close(data), 0);
	h = 0;
	while (h < data->map->height)
	{
		if (width != ft_strlen_nl(data->map->map[h]))
			return (write(2, "ERROR\n YOUR MAP IS NOT A RECTANGLE\n", 35),
				ft_close(data), 0);
		h++;
	}
	data->map->width = (int)width;
	if (!(ft_validate_walls(data, h, width)))
		return (write(2, "ERROR\n INVALID WALLS\n", 21),
			ft_close(data), 0);
	if (!(ft_message_error(data)))
		return (0);
	data->map->colection = ft_message_error(data);
	return (1);
}
