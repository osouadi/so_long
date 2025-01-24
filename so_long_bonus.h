/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osouadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:25:27 by osouadi           #+#    #+#             */
/*   Updated: 2025/01/06 13:40:02 by osouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx/mlx.h"
# include "get_next_line_bonus.h"
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
	int		enmy_x;
	int		enmy_y;
	size_t	character_move;
	int		colection;
	int		enmy;
}	t_map;

typedef struct t_data
{
	void	*win_ptr;
	void	*mlx_ptr;
	void	*wall_img;
	void	*floor_img;
	void	*collection_img;
	void	*character_img;
	void	*character1;
	void	*character2;
	void	*exit_img;
	void	*enmy_img;
	t_map	*map;
}	t_data;

int		ft_animation(t_data *data);
int		ft_key(int key, t_data *data);
void	ft_put_enmy(t_data *data, int x, int y);
void	ft_check(t_data *data, int *j, int *i, int *dir);
void	ft_enmy_img(t_data *data, int x, int y);
int		ft_valid_path(t_data *data, int nmbc);
void	*ft_src_img(t_data *data, char *src);
void	ft_put_to_window(t_data *data, int x, int y, void *img);
void	ft_print(t_data *data);
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
