/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 21:49:06 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// charger toutes les images, redimansionner image sur gimp, verifier couleurs supporter par mlx extention xpm
// dessiner toutes les images 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// fonction qui lit les deplaceement du peripherique au jeu
//  fonction pour les mur et recuperer collectible ou sortie 
// ennemies bonus et animation 

int	player_mouvement(t_all *all, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = all->data->pos_x;
	pos_y = all->data->pos_y;
	if ( all->game->map[pos_y + y][pos_x + x] != '1')
	{
		if (all->game->map[pos_y + y][pos_x + x] == 'C')
			all->game->collec_missing -= 1;
		else if (all->game->map[pos_y + y][pos_x + x] == 'E' && all->game->collec_missing == 0)
			return (1);
		else if (all->game->map[pos_y + y][pos_x + x] == 'D')
			return (404);
		all->game->map[pos_y + y][pos_x + x] = 'P';
		all->game->map[pos_y][pos_x] = '0';
		all->data->pos_x += x;
		all->data->pos_y += y;
	}
	delete_all_image(all->data);
	display_all(all);
	return (0);
}

int	key_pressed(int	touch, t_all *all)
{
	int win;
	
	win = 0;
	if ( touch == ESC)
		close_wind(all);
	if ( touch == RIGHT)
		win = player_mouvement(all, 1, 0);
	if ( touch == LEFT)
		win = player_mouvement(all, -1, 0);
	if ( touch == UP)
		win = player_mouvement(all, 0, -1);
	if ( touch == DOWN)
		win = player_mouvement(all, 0, 1);
	if ( win == 1)
	{
		ft_putstr_fd("Victory\n", 1);
		close_wind(all);
	}
	else if ( win == 404)
	{
		ft_putstr_fd("You've been caught.", 1);
		close_wind(all);
	}
	return (0);
}


int main(int ac , char **av)
{
	if (ac == 1 || !av[1] || av[1][0] == 0 || !check_map_format(av[1]))
		return (ft_putstr_fd("Missing Map\n", 1), 1);
	t_game		game;
	t_data		data;
	t_all		all;

	all.data = &data;
	all.game = &game;
	game.map = extract_map(av);
	if (first_check(game.map))
		return (1);
	struct_atribution(game.map, &all);
	if (check_all(all.game->map, &all)) // Je free ici en cas derreur 
		return (1);
	if(wind_creation(&all))
		return (1);	
	if (display_all(&all))
		return (1);
	mlx_hook(all.data->win, 2, 1L<<0, key_pressed, &all);
	mlx_hook((&data)->win, CLOSE_MOUSE, 0, close_wind, &all);
	mlx_loop((&data)->mlx);
	return (0);
}
