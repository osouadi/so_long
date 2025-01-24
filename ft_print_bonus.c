/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:19:07 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/04 20:19:09 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_img(void *img, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, img, x * SIZE, y * SIZE);
}

void	ft_print(t_data *data)
{
	char	*str_move;

	str_move = ft_itoa(data->map->character_move);
	if (str_move == 0)
		ft_close(data);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 110, 12, 0x44F853,
		str_move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 12, -1,
		"Number of moves:");
	free (str_move);
}

void	ft_put_to_window(t_data *data, int x, int y, void *img)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img, x * SIZE, y * SIZE);
}

void	*ft_src_img(t_data *data, char *src)
{
	int	x;
	int	y;

	return (mlx_xpm_file_to_image(data->mlx_ptr, src, &x, &y));
}
