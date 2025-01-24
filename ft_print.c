/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:14:54 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:14:56 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(void *img, int x, int y, t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, img, x * SIZE, y * SIZE);
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
