/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/02/01 11:10:10 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-linux/mlx.h"
# include "ft_printf_fd.h"
# include "get_next_line.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map_data;
	int				map_width;
	int				map_height;
	void			*grass_img;
	void			*wall_img;
	void			*macron_img;
	void			*money_img;
	void			*exit_img;
	void			*win_img;
	int				px;
	int				py;
	int				coins;
	int				moves;
	int				ended;
}					t_game;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_printf_fd(int fd, const char *format, ...);

void				error_exit(t_game *g, const char *msg);
void				initializate_g(t_game *g);
void				read_map(char *filepath, t_game *g);
void				find_player(t_game *g);
void				load_textures(t_game *g);

void				draw_tile(t_game *g, char c, int x, int y);
void				draw_map(t_game *g);
void				draw_player(t_game *g);
void				draw_win_message(t_game *g);
void				render(t_game *g);

int					close_win(t_game *g);
void				move_player(t_game *g, int nx, int ny);
int					key_hook(int keycode, t_game *g);

#endif //FT_H
