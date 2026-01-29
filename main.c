/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 10:34:06 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// charger toutes les images, redimansionner image sur gimp, verifier couleurs supporter par mlx extention xpm
// dessiner toutes les images 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// fonction qui lit les deplaceement du peripherique au jeu
//  fonction pour les mur et recuperer collectible ou sortie 
// ennemies bonus et animation 
 
int main(int ac , char **av)
{
	if (ac == 1)
		return (ft_putstr_fd("Missing Map\n", 1), 1);
	t_game	game;
	t_data		data;
	t_all		all;

	all.data = &data;
	all.game = &game;
	game.map = extract_map(av);
	struct_atribution(game.map, &game);
	if (check_all(game.map, &game, av[1])) // Je free ici en cas derreur 
		return (1);
	if(wind_creation(&data, &game))
		return (1);	
	if (display_all(&all))
		return (1); //deja free
	
	mlx_hook((&data)->win, CLOSE_MOUSE, 0, close_wind, &all);
	mlx_loop((&data)->mlx);

	return (0);
}

