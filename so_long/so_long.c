/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:59:30 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 15:35:15 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	g;
	int	fd;
	
	if (argc != 2)
		error_exit("Usage: ./so_long <map.ber>");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		(close(fd), error_exit("Usage: ./so_long <map.ber>"));
	if (is_map_error(argv[1]) == 1)
		error_exit("map.ber not valid");
	g.moves = 1;
	(initializate_g(&g), read_map(argv[1], &g));
	g.mlx_ptr = mlx_init();
	if (!g.mlx_ptr)
		error_exit("Failed to init MiniLibX");
	g.win_ptr = mlx_new_window(g.mlx_ptr, g.map_width * TILE_SIZE, g.map_height
			* TILE_SIZE, "so_long");
	if (!g.win_ptr)
		error_exit("Failed to create a window");
	(load_textures(&g), find_player(&g), render(&g));
	mlx_hook(g.win_ptr, 2, 1L << 0, key_hook, &g);
	mlx_hook(g.win_ptr, 17, 0, close_win, &g);
	mlx_loop(g.mlx_ptr);
	return (0);
}
