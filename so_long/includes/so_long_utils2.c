/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:29:32 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 17:46:40 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *g, char c, int x, int y)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->grass_img, x * TILE_SIZE,
		y * TILE_SIZE);
	if (c == '1')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->wall_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->money_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (c == 'E')
	{
		if (g->coins == 0)
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->exit_img, x
				* TILE_SIZE, y * TILE_SIZE);
	}
}

void	draw_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			draw_tile(g, g->map_data[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->macron_img, g->px
		* TILE_SIZE, g->py * TILE_SIZE);
}

void	draw_win_message(t_game *g)
{
	int	win_img_width;
	int	win_img_height;
	int	center_x;
	int	center_y;

	win_img_width = 256;
	win_img_height = 64;
	center_x = (g->map_width * TILE_SIZE - win_img_width) / 2;
	center_y = (g->map_height * TILE_SIZE - win_img_height) / 2;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_img, center_x,
		center_y);
}

void	render(t_game *g)
{
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	draw_map(g);
	draw_player(g);
	if (g->ended)
		draw_win_message(g);
}
