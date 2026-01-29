/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:32:08 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 21:49:02 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	delete_all_image(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->floor)
		mlx_destroy_image(data->mlx, data->floor);
	if (data->colectible)
		mlx_destroy_image(data->mlx, data->colectible);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->danger)
		mlx_destroy_image(data->mlx, data->danger);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->player_med)
		mlx_destroy_image(data->mlx, data->player_med);
	if (data->player_end)
		mlx_destroy_image(data->mlx, data->player_end);
	return (0);
}

int	close_wind(t_all *all)
{
	delete_all_image(all->data);
	if ( all->data->win)
		mlx_destroy_window(all->data->mlx, all->data->win);
	if ( all->data->mlx)
	{
		mlx_destroy_display(all->data->mlx);
		free(all->data->mlx);
	}
	if ( all->game->map)
		free_tab(all->game->map);
	exit(0);
	return (0);
}
