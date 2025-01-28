/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:59:30 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/28 10:58:09 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void error_exit(const char *msg)
{
    write(2, "Error\n", 6);
    if (msg)
        write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

void initializate_g(t_game *g)
{
    g->coins = 0;
    g->ended = 0;
    g->map_height = 0;
    g->map_width = 0;
    g->map_data = NULL;
    g->px = 0;
    g->py = 0;
    g->moves = 0;
}

static void read_map(char *filepath, t_game *g)
{
    char *str;
    
    str = read_txt(filepath);
	g->map_data = df(str);
    free(str);
    g->coins = n_c(g->map_data);
    g->map_height = str_len_2d(g->map_data);
    g->map_width = ft_strlen((g->map_data)[0]);
    if (g->map_height == 0 || g->map_width == 0)
        error_exit("Empty or invalid map file");
}

static void find_player(t_game *g)
{
    int y = 0;
    while (y < g->map_height)
    {
        int x = 0;
        while (x < g->map_width)
        {
            if (g->map_data[y][x] == 'P')
            {
                g->px = x;
                g->py = y;
                g->map_data[y][x] = '0';
                return;
            }
            x++;
        }
        y++;
    }
}

static void load_textures(t_game *g)
{
    int w, h;

    g->grass_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/grass.xpm", &w, &h);
    if (!g->grass_img)
        error_exit("Failed to load grass.xpm");
    g->wall_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/wall.xpm", &w, &h);
    if (!g->wall_img)
        error_exit("Failed to load wall.xpm");
    g->macron_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/macron.xpm", &w, &h);
    if (!g->macron_img)
        error_exit("Failed to load macron.xpm");
    g->money_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/money.xpm", &w, &h);
    if (!g->money_img)
        error_exit("Failed to load money.xpm");
    g->exit_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/exit.xpm", &w, &h);
    if (!g->exit_img)
        error_exit("Failed to load exit.xpm");
    g->win_img = mlx_xpm_file_to_image(g->mlx_ptr, "textures/win.xpm", &w, &h);
    if (!g->win_img)
        error_exit("Failed to load win.xpm");
        
}

static void draw_tile(t_game *g, char c, int x, int y)
{
    mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
        g->grass_img, x * TILE_SIZE, y * TILE_SIZE);
    if (c == '1')
        mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
            g->wall_img, x * TILE_SIZE, y * TILE_SIZE);
    else if (c == 'C')
        mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
            g->money_img, x * TILE_SIZE, y * TILE_SIZE);
    else if (c == 'E')
    {
        if (g->coins == 0)
            mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
                g->exit_img, x * TILE_SIZE, y * TILE_SIZE);
        else
            ;
    }
}

static void draw_map(t_game *g)
{
    int y = 0;
    while (y < g->map_height)
    {
        int x = 0;
        while (x < g->map_width)
        {
            draw_tile(g, g->map_data[y][x], x, y);
            x++;
        }
        y++;
    }
}

static void draw_player(t_game *g)
{
    mlx_put_image_to_window(g->mlx_ptr, g->win_ptr,
        g->macron_img, g->px * TILE_SIZE, g->py * TILE_SIZE);
}

static void draw_win_message(t_game *g)
{
    int win_img_width;
    int win_img_height;

    win_img_width = 256;
    win_img_height = 64;
    int center_x = (g->map_width * TILE_SIZE - win_img_width) / 2;
    int center_y = (g->map_height * TILE_SIZE - win_img_height) / 2;

    mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->win_img, center_x, center_y);
}

static void render(t_game *g)
{
    mlx_clear_window(g->mlx_ptr, g->win_ptr);
    draw_map(g);
    draw_player(g);
    if (g->ended)
        draw_win_message(g);
}

static int close_win(t_game *g)
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

static void move_player(t_game *g, int nx, int ny)
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
        printf("Moves: %d\n", g->moves);
        g->ended = 1;
        render(g);
        return;
    }
    if (g->map_data[ny][nx] == 'E' && g->coins > 0)
        return;
    g->px = nx;
    g->py = ny;
    g->moves++;
    printf("Moves: %d\n", g->moves);
}

static int key_hook(int keycode, t_game *g)
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



int main(int argc, char **argv)
{
    t_game g;

    if (argc != 2)
        error_exit("Usage: ./so_long <map.ber>");
    g.moves = 0;
    initializate_g(&g);
    read_map(argv[1], &g);
    g.mlx_ptr = mlx_init();
    if (!g.mlx_ptr)
        error_exit("Failed to init MiniLibX");
    g.win_ptr = mlx_new_window(g.mlx_ptr, g.map_width * TILE_SIZE,
        g.map_height * TILE_SIZE, "so_long");
    if (!g.win_ptr)
        error_exit("Failed to create a window");
    load_textures(&g);
    find_player(&g);
    render(&g);
    mlx_hook(g.win_ptr, 2, 1L << 0, key_hook, &g);
    mlx_hook(g.win_ptr, 17, 0, close_win, &g);
    mlx_loop(g.mlx_ptr);
    return (0);
}

