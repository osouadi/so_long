/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_help_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:16:56 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/04 20:16:59 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check(t_data *data, int *j, int *i, int *dir)
{
	if (data->map->map[*i][*j] == 'B'
			&& data->map->map[*i][*j + 1] == '0' && *dir == 0)
	{
		data->map->map[*i][*j] = '0';
		*j += 1;
		data->map->map[*i][*j] = 'B';
		*dir = 1;
		ft_put_enmy(data, 0, 0);
	}
	else if (data->map->map[*i][*j] == 'B'
			&& data->map->map[*i][*j - 1] == '0' && (*dir == 1 || *dir == 0))
	{
		data->map->map[*i][*j] = '0';
		*j -= 1;
		data->map->map[*i][*j] = 'B';
		*dir = 0;
		ft_put_enmy(data, 0, 0);
	}
	else if (data->map->map[*i][*j] == 'B' && data->map->map[*i][*j + 1] == '1'
			&& data->map->map[*i][*j - 1] == '1')
	{
		data->map->map[*i][*j] = 'B';
		ft_put_enmy(data, 0, 0);
	}
}
