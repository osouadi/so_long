/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:18:09 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:18:11 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int arc, char **arv)
{
	t_data	data;

	if (arc == 2)
	{
		data.map = malloc(sizeof(t_map));
		if (!data.map)
			ft_close(&data);
		ft_init_map(data.map, &data);
		ft_read_map(&data, arv[1]);
		ft_mlx(&data);
	}
	else
		return (write(2, "ERROR\nARGV\n", 13));
	return (0);
}
