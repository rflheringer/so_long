/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:35:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/04 18:23:10 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#define WIDTH 512
#define HEIGHT 512

#define TILE_SIZE 32
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void fill_screen_with_terrain(void *mlx, void *img)
{
    int x, y;

    y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			mlx_image_to_window(mlx, img, x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

int32_t init_window(void)
{
    mlx_t *mlx;
    void *img_terrain;

    mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "so_long", false);
    if (!mlx)
        return (1);
    mlx_texture_t *texture = mlx_load_png("assets/grass.png");
	if (!texture)
	{
    	printf("Erro ao carregar a textura.\n");
    	return (1);
	}
	img_terrain = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
    if (!img_terrain)
    {
        printf("Erro ao carregar a imagem do terreno.\n");
        return (1);
    }
    fill_screen_with_terrain(mlx, img_terrain);
    mlx_loop(mlx);
    return (0);
}