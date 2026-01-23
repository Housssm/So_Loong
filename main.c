/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/23 22:00:47 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_circle(t_data *img, int cx, int cy, int radius, int color)
{
    int	x;
    int	y;

    y = cy - radius;
    while (y <= cy + radius)
    {
        x = cx - radius;
        while (x <= cx + radius)
        {
            if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= radius * radius)
                my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 700, 400, "So_long");
// charger toutes les images, redimansionner image sur gimp, verifier couleurs supporter par mlx extention xpm
// dessiner toutes les images 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// fonction qui lit les deplaceement du peripherique au jeu
//  fonction pour les mur et recuperer collectible ou sortie 
// ennemies bonus et animation 
	img.img = mlx_new_image(mlx, 700, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_circle(&img, 350, 200, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}


// int main(int ac , char **av)\
// {
// 	(void)ac;
// 	(void)av;
// 	// char **tab;
// 	// t_game	*game;
	
// 	// game = (t_game *)malloc(sizeof(t_game));
// 	// tab = extract_map(av);
// 	// struct_atribution(tab, game);
// 	// if (check_all(tab, game, av[1])) // Je free ici en cas derreur 
// 	// 	return (1);
		
// 	void	*img;
// 	void	*mlx;

// 	mlx = mlx_init();
// 	img = mlx_new_image(mlx, 1920, 1080);	
	
// 	// free_tab(tab);
// 	// free(game);
// 	return (0);
// }

