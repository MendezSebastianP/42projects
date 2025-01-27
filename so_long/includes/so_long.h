/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:30:42 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/27 17:03:16 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include "ft_printf_fd.h"
# include "../minilibx-linux/mlx.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#define TILE_SIZE 64

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

typedef struct s_game
{
    void    *mlx_ptr;
    void    *win_ptr;
    char    **map_data;
    int     map_width;
    int     map_height;
    void    *grass_img;
    void    *wall_img;
    void    *macron_img;
    void    *money_img;
    void    *exit_img;
    void    *win_img;
    int     px;
    int     py;
    int     coins;
    int     moves;
    int     ended;
}   t_game;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif //FT_H
