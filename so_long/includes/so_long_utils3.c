/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:32:11 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 13:42:57 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(t_game *g)
{
    cleanexit(g->map_data);
    if (g->grass_img)
        mlx_destroy_image(g->mlx_ptr, g->grass_img);
    if (g->exit_img)
        mlx_destroy_image(g->mlx_ptr, g->exit_img);
    if (g->macron_img)
        mlx_destroy_image(g->mlx_ptr, g->macron_img);
    if (g->wall_img)
        mlx_destroy_image(g->mlx_ptr, g->wall_img);
    if (g->money_img)
        mlx_destroy_image(g->mlx_ptr, g->money_img);
    if (g->win_img)
        mlx_destroy_image(g->mlx_ptr, g->win_img);
    if (g->mlx_ptr)
    {
        mlx_destroy_window(g->mlx_ptr, g->win_ptr);
        mlx_destroy_display(g->mlx_ptr);
        free(g->mlx_ptr);
    }
    exit(0);
    return (0);
}

void move_player(t_game *g, int nx, int ny)
{
    if (g->ended)
        return;
    if (nx < 0 || ny < 0 || ny >= g->map_height || nx >= g->map_width)
        return;
    if (g->map_data[ny][nx] == '1')
        return;
    if (g->map_data[ny][nx] == 'C')
    {
        g->coins--;
        g->map_data[ny][nx] = '0';
    }
    if (g->map_data[ny][nx] == 'E' && g->coins == 0)
    {
        g->px = nx;
        g->py = ny;
        g->moves++;
        g->ended = 1;
        (render(g), printf("Moves: %d\n", g->moves));
        return;
    }
    if (g->map_data[ny][nx] == 'E' && g->coins > 0)
        return;
    g->px = nx;
    g->py = ny;
    printf("Moves: %d\n", g->moves++);
}

int key_hook(int keycode, t_game *g)
{
    if (keycode == KEY_ESC)
        close_win(g);
    else if (keycode == KEY_W)
        move_player(g, g->px, g->py - 1);
    else if (keycode == KEY_S)
        move_player(g, g->px, g->py + 1);
    else if (keycode == KEY_A)
        move_player(g, g->px - 1, g->py);
    else if (keycode == KEY_D)
        move_player(g, g->px + 1, g->py);
    render(g);
    return (0);
}
