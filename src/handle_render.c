/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:35:25 by rheringe          #+#    #+#             */
/*   Updated: 2025/02/06 18:20:31 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void fill_screen_with_terrain(t_game *game)
{
    int i;
	int j;

    i = -1;
	while (i++, game->map.matrix[i])
	{
		j = -1;
		while (j++, game->map.matrix[i][j])
		{
			mlx_image_to_window(game->mlx, game->map.ground_img, i * TILE_SIZE, j * TILE_SIZE);
		}
	}
}

// void load_wall_tiles(t_map *map)
// {
//     mlx_texture_t *texture;

//     // Carrega a parede 1
//     texture = mlx_load_png("../assets/lapide.png");
//     if (!texture)
//     {
//         printf("Erro ao carregar a textura: wall1.png\n");
//         exit(1);
//     }
//     map->wall1 = mlx_texture_to_image(mlx, texture);
//     mlx_delete_texture(texture);

//     //Carrega a parede 2
//     texture = mlx_load_png("../assets/lapide.png");
//     if (!texture)
//     {
//         printf("Erro ao carregar a textura: wall2.png\n");
//         exit(1);
//     }
//     map->wall2 = mlx_texture_to_image(mlx, texture);
//     mlx_delete_texture(texture);
// }

// 
// void render_walls(t_game *game)
// {
//     int x, y;
//     int tile_index;

//     srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

//     y = 0;
//     while (y < game->map.height)
//     {
//         x = 0;
//         while (x < game->map.width)
//         {
//             // Se a posição no mapa for uma parede ('1')
//             if (game->map.matrix[y][x] == '1')
//             {
//                 // Escolhe uma parede aleatória (wall1 ou wall2)
//                 tile_index = rand() % 2; // Gera 0 ou 1

//                 // Renderiza a parede escolhida
//                 if (tile_index == 0)
//                     mlx_image_to_window(mlx, game->map.wall1, x * TILE_SIZE, y * TILE_SIZE);
//                 else
//                     mlx_image_to_window(mlx, game->map.wall2, x * TILE_SIZE, y * TILE_SIZE);
//             }
//             x++;
//         }
//         y++;
//     }
// }

int32_t init_window(t_game *game)
{

    game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long", false);
    if (!game->mlx)
        return (1);
    mlx_texture_t *texture = mlx_load_png("assets/grass.png");
	if (!texture)
	{
    	printf("Erro ao carregar a textura.\n");
    	return (1);
	}
	game->map.ground_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	mlx_resize_image(game->map.ground_img, TILE_SIZE, TILE_SIZE);
    fill_screen_with_terrain(game);
    mlx_loop(game->mlx);
    return (0);
}