/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:28:55 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 15:35:10 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(const char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	initializate_g(t_game *g)
{
	g->coins = 0;
	g->ended = 0;
	g->map_height = 0;
	g->map_width = 0;
	g->map_data = NULL;
	g->px = 0;
	g->py = 0;
	g->moves = 1;
}

void	read_map(char *filepath, t_game *g)
{
	char	*str;

	str = read_txt(filepath);
	g->map_data = df(str);
	free(str);
	g->coins = n_c(g->map_data);
	g->map_height = str_len_2d(g->map_data);
	g->map_width = ft_strlen((g->map_data)[0]);
	if (g->map_height == 0 || g->map_width == 0)
		error_exit("Empty or invalid map file");
}

void	find_player(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map_height)
	{
		x = 0;
		while (x < g->map_width)
		{
			if (g->map_data[y][x] == 'P')
			{
				g->px = x;
				g->py = y;
				g->map_data[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	load_textures(t_game *g)
{
	int	w;
	int	h;

	g->grass_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/grass.xpm", &w,
			&h);
	if (!g->grass_img)
		error_exit("Failed to load grass.xpm");
	g->wall_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/wall.xpm", &w,
			&h);
	if (!g->wall_img)
		error_exit("Failed to load wall.xpm");
	g->macron_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/macron.xpm", &w,
			&h);
	if (!g->macron_img)
		error_exit("Failed to load macron.xpm");
	g->money_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/money.xpm", &w,
			&h);
	if (!g->money_img)
		error_exit("Failed to load money.xpm");
	g->exit_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/exit.xpm", &w,
			&h);
	if (!g->exit_img)
		error_exit("Failed to load exit.xpm");
	g->win_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/win.xpm", &w, &h);
	if (!g->win_img)
		error_exit("Failed to load win.xpm");
}
