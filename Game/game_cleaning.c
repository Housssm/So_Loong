/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:32:08 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 10:37:39 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
