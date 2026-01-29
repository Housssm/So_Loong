/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 10:08:00 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// charger toutes les images, redimansionner image sur gimp, verifier couleurs supporter par mlx extention xpm
// dessiner toutes les images 	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
// fonction qui lit les deplaceement du peripherique au jeu
//  fonction pour les mur et recuperer collectible ou sortie 
// ennemies bonus et animation 



int	delete_all_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->colectible);
	mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_image(data->mlx, data->exit);
	return (0);
}


int	close_wind(t_all *all)
{
    delete_all_image(all->data);
    mlx_destroy_window(all->data->mlx, all->data->win);
    mlx_destroy_display(all->data->mlx);
    free(all->data->mlx);
    free_tab(all->game->map);
    exit(0);
    return (0);
}

// int	close_wind(t_all *all)
// {
// 	delete_all_image(all->data);
// 	mlx_destroy_window(all->data->mlx, all->data->win);
// 	mlx_destroy_display(all->data->mlx);
// 	free(all->data->mlx);

// 	exit(0);
// 	return (0);
// }
int	wind_creation(t_data	*data, t_game *game)
{
	int	width;
	int	height;

	width = game->cols * BITS_SIZE;
	height = game->row * BITS_SIZE; 
	data->mlx = mlx_init();
	if ( !data->mlx)
		return (free(data->mlx), 1);
	data->win = mlx_new_window(data->mlx, width, height, WIND_NAME);
	if ( !data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (1);
	}
	return (0);
}


int	file_to_img(t_data	*data)
{
    data->wall= mlx_xpm_file_to_image(data->mlx, "Images/wall_bank.xpm", &data->w, &data->h);
    data->floor= mlx_xpm_file_to_image(data->mlx, "Images/floor_bank.xpm", &data->w, &data->h);
    data->colectible= mlx_xpm_file_to_image(data->mlx, "Images/biff.xpm", &data->w, &data->h);
    data->player= mlx_xpm_file_to_image(data->mlx, "Images/Robber_beg.xpm", &data->w, &data->h);
    data->exit= mlx_xpm_file_to_image(data->mlx, "Images/exit.xpm", &data->w, &data->h);

	if (!data->wall || !data->floor || !data->colectible 
        || !data->player || !data->exit)
        return ( 1);
	return (0);
}


int	display_all(t_data *data,t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (file_to_img(data))
		return (1);
		
	while(game->map[i])
	{
		j = 0;
		while ( game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall , j * BITS_SIZE, i * BITS_SIZE);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->floor , j * BITS_SIZE, i * BITS_SIZE);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->colectible , j * BITS_SIZE, i * BITS_SIZE);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->player , j * BITS_SIZE, i * BITS_SIZE);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit , j * BITS_SIZE, i * BITS_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}


 
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
	display_all(&data, &game );
	mlx_hook((&data)->win, CLOSE_MOUSE, 0, close_wind, &all);
	mlx_loop((&data)->mlx);

	return (0);
}

