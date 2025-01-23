/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smendez- <smendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:59:30 by smendez-          #+#    #+#             */
/*   Updated: 2025/01/23 13:38:43 by smendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void get_map_dimensions(const char *file_path, int *width, int *height)
{
    FILE *file = fopen(file_path, "r");
    if (!file)
    {
        perror("Error opening map file");
        exit(EXIT_FAILURE);
    }

    char ch;
    *width = 0;
    *height = 0;
    int current_width = 0;

    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            if (*width == 0)
                *width = current_width;
            else if (current_width != *width)
            {
                fprintf(stderr, "Error: Inconsistent line lengths in map file.\n");
                exit(EXIT_FAILURE);
            }
            current_width = 0;
            (*height)++;
        }
        else
        {
            current_width++;
        }
    }
    fclose(file);
}

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int img_width;
    int img_height;
    int map_width;
    int map_height;

    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error initializing MLX.\n");
        return EXIT_FAILURE;
    }
    get_map_dimensions("maps/map7.ber", &map_width, &map_height);

    img = mlx_xpm_file_to_image(mlx, "textures/grass.xpm", &img_width, &img_height);
    if (!img)
    {
        fprintf(stderr, "Error loading texture.\n");
        return EXIT_FAILURE;
    }
    win = mlx_new_window(mlx, map_width * img_width, map_height * img_height, "so_long");
    if (!win)
    {
        fprintf(stderr, "Error creating window.\n");
        return EXIT_FAILURE;
    }
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            mlx_put_image_to_window(mlx, win, img, x * img_width, y * img_height);
        }
    }
    mlx_loop(mlx);
    return EXIT_SUCCESS;
}


