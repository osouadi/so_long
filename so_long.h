/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:18:22 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/06 13:40:14 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ESC			65307
# define A				97
# define W				119
# define S				115
# define D				100
# define LEFT			65361
# define RIGHT			65363
# define DOWN			65364
# define UP				65362
# define SIZE			32

typedef struct t_map
{
	char	**map;
	char	**cpy;
	int		width;
	int		height;
	int		character_x;
	int		character_y;
	size_t	character_move;
	int		colection;
}	t_map;

typedef struct t_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*wall_img;
	void	*floor_img;
	void	*collection_img;
	void	*character_img;
	void	*exit_img;
	t_map	*map;
}	t_data;

void	ft_putnbr_n(int n);
int		ft_valid_path(t_data *data, int nmbc);
void	*ft_src_img(t_data *data, char *src);
void	ft_put_to_window(t_data *data, int x, int y, void *img);
char	*ft_itoa(int n);
int		ft_mlx(t_data *data);
void	ft_init_map(t_map *map, t_data *data);
int		ft_validate_file_ext(char *file);
int		ft_read_map(t_data *data, char *file);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen_nl(const char *str);
int		ft_valide(t_data *data);
int		ft_validate_walls(t_data *data, int h, int width);
int		ft_close(t_data *data);
void	ft_put_img(void *img, int x, int y, t_data *data);
void	coloring_map(t_data *data, int x, int y);

#endif
