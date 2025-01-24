/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:15:40 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/05 17:15:42 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_help(int h, char *line, t_data *data)
{
	if (!line
		&& data->map->map[h][ft_strlen(data->map->map[h]) - 1] == '\n')
	{
		return (0);
	}
	return (1);
}

static int	ft_file_exist(char *file)
{
	int		i;
	int		len;
	int		len_str;
	char	*ber;

	i = 0;
	ber = ".ber";
	len = ft_strlen(file) - 1;
	len_str = ft_strlen(ber) - 1;
	if (len == 0)
		return (0);
	while (len > 0 && len_str > 0 && ber[len_str])
	{
		if (file[len] != ber[len_str])
			return (0);
		len--;
		len_str--;
	}
	return (1);
}

static int	ft_get_height(t_data *data, char *file)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "ERROR\nYOU HAVE A INVALID FD\n", 28),
			ft_close(data), 0);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	data->map->height = i;
	close(fd);
	return (i);
}

static int	ft_get_line(t_data *data, char *file, int height, char *line)
{
	int		fd;

	height = data->map->height;
	data->map->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!data->map->map)
		return (write(2, "ERROR\nMEMORY ALLOCATION FOR MAP\n", 32),
			ft_close(data), 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write(2, "ERROR\nYOU HAVE A INVALID FD\n", 28),
			ft_close(data), 0);
	line = get_next_line(fd);
	height = 0;
	while (line)
	{
		data->map->map[height] = ft_strdup(line);
		if (!data->map->map[height])
			return (close(fd), ft_close(data), 0);
		free(line);
		line = get_next_line(fd);
		if (!ft_help(height, line, data))
			return (write(2, "ERROR\nNEW LINE\n", 15), ft_close(data), 0);
		height++;
	}
	return (data->map->map[height] = 0, close(fd), 1);
}

int	ft_read_map(t_data *data, char *file)
{
	char	*line;

	line = 0;
	if (!(ft_validate_file_ext(file)))
		return (write(2, "Error\nINVALID FILE EXTENSION\n", 30),
			ft_close(data), 0);
	if (!(ft_file_exist(file)))
		return (write(2, "Error\nFILE.BER\n", 16), ft_close(data), 0);
	if (!(ft_get_height(data, file)))
		return (write(2, "Error\nINVALIDE MAB\n", 20), ft_close(data), 0);
	if (!(ft_get_line(data, file, 0, line)))
		return (write(2, "Error\nINVALIDE MAB\n", 20), ft_close(data), 0);
	ft_valide(data);
	if (data->map->height == 0)
		return (write(2, "Error\nMAP\n", 11), ft_close(data), 0);
	return (1);
}
