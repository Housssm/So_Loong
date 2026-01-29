/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:01:26 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 10:06:57 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_lentab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
void	remove_newline(char **tab)
{
	int	i;
	int	j;
	
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ( tab[i][j] == '\n')
				tab[i][j] = '\0';
			j++;
		}
		i++;
	}
}


// void	fill_display(t_all *all, size_t i, size_t j)
// {
// 	if (all->game->map[i][j] == '1')
// 		mlx_put_image_to_window(all->data->mlx, all->data->win, all->data->wall , j * BITS_SIZE, i * BITS_SIZE);
// 	else if (all->game->map[i][j] == '0')
// 		mlx_put_image_to_window(all->data->mlx, all->data->win, all->data->floor , j * BITS_SIZE, i * BITS_SIZE);
// 	else if (all->game->map[i][j] == 'C')
// 		mlx_put_image_to_window(all->data->mlx, all->data->win, all->data->colectible , j * BITS_SIZE, i * BITS_SIZE);
// 	else if (all->game->map[i][j] == 'P')
// 		mlx_put_image_to_window(all->data->mlx, all->data->win, all->data->player , j * BITS_SIZE, i * BITS_SIZE);
// 	else if (all->game->map[i][j] == 'E')
// 		mlx_put_image_to_window(all->data->mlx, all->data->win, all->data->exit , j * BITS_SIZE, i * BITS_SIZE);
// }


// int	display_all(t_all *all)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	if (file_to_img(all->data))
// 		return (1);
// 	while (all->game->map[i])
// 	{
// 		j = 0;
// 		while (all->game->map[i][j])
// 		{
// 			fill_display(all, i , j);
// 			// if (game->map[i][j] == '1')
// 			// 	mlx_put_image_to_window(data->mlx, data->win, data->wall , j * BITS_SIZE, i * BITS_SIZE);
// 			// else if (game->map[i][j] == '0')
// 			// 	mlx_put_image_to_window(data->mlx, data->win, data->floor , j * BITS_SIZE, i * BITS_SIZE);
// 			// else if (game->map[i][j] == 'C')
// 			// 	mlx_put_image_to_window(data->mlx, data->win, data->colectible , j * BITS_SIZE, i * BITS_SIZE);
// 			// else if (game->map[i][j] == 'P')
// 			// 	mlx_put_image_to_window(data->mlx, data->win, data->player , j * BITS_SIZE, i * BITS_SIZE);
// 			// else if (game->map[i][j] == 'E')
// 			// 	mlx_put_image_to_window(data->mlx, data->win, data->exit , j * BITS_SIZE, i * BITS_SIZE);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }