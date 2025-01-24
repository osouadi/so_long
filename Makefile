RSRCSXB = \
	ft_validate_file_ext_bonus.c \
	get_next_line_utils_bonus.c \
	get_next_line_bonus.c \
	mini_itoa_bonus.c \
	ft_mlx_bonus.c \
	ft_close_and_free_bonus.c \
	ft_read_map_bonus.c \
	check_map_bonus.c \
	check_wall_and_path_bonus.c \
	take_rsc_and_put_bonus.c \
	ft_print_bonus.c \
	ft_animations_bonus.c \
	ft_animation_help_bonus.c \
	so_long_bonus.c
RSRCSX = \
	ft_validate_file_ext.c \
	get_next_line_utils.c \
	get_next_line.c \
	mini_itoa.c \
	ft_mlx.c \
	ft_close_and_free.c \
	ft_read_map.c \
	check_map.c \
	check_wall_and_path.c \
	take_rsc_and_put.c \
	ft_print.c \
	ft_putnbr.c \
	so_long.c
NAME = so_long
BNAME = so_long_bonus
ORSRCSXB = ${RSRCSXB:.c=.o}
ORSRCSX = ${RSRCSX:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(ORSRCSX)
	cc $(CFLAGS) $^ -L mlx/ -lmlx -lX11 -lXext -o $@

$(ORSRCSX): %.o: %.c so_long.h
	cc $(CFLAGS) -c $< -o $@

$(BNAME): $(ORSRCSXB)
	cc $(CFLAGS) $^ -L mlx/ -lmlx -lX11 -lXext -o $@

$(ORSRCSXB): %.o: %.c so_long_bonus.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ORSRCSX)
	rm -f $(ORSRCSXB)

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)

re: fclean all

.PHONY: clean
