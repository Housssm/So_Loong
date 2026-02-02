/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:28:38 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/02 11:07:15 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wind_creation(t_all *all)
{
	int	width;
	int	height;

	width = all->game->cols * BITS_SIZE;
	height = all->game->row * BITS_SIZE;
	all->data->mlx = mlx_init();
	if (!all->data->mlx)
	{
		ft_putstr_fd("Error\nMLX init failed\n", 2);
		free_tab(all->game->map);
		exit(1);
	}
	all->data->win = mlx_new_window(all->data->mlx, width, height, WIND_NAME);
	if (!all->data->win)
	{
		mlx_destroy_display(all->data->mlx);
		free(all->data->mlx);
		free_tab(all->game->map);
		return (1);
	}
	return (0);
}

int	file_to_img(t_data	*data)
{
	data->wall = mlx_xpm_file_to_image(data->mlx, IMG_WALL, &data->w, &data->h);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			IMG_FLOOR, &data->w, &data->h);
	data->colectible = mlx_xpm_file_to_image(data->mlx,
			IMG_COLL, &data->w, &data->h);
	data->player = mlx_xpm_file_to_image(data->mlx,
			IMG_PLAYER, &data->w, &data->h);
	data->player_med = mlx_xpm_file_to_image(data->mlx,
			IMG_PLAYER2, &data->w, &data->h);
	data->player_end = mlx_xpm_file_to_image(data->mlx,
			IMG_PLAYER3, &data->w, &data->h);
	data->exit = mlx_xpm_file_to_image(data->mlx, IMG_EXIT, &data->w, &data->h);
	data->danger = mlx_xpm_file_to_image(data->mlx, IMG_DANG,
			&data->w, &data->h);
	if (!data->wall || !data->floor || !data->colectible
		|| !data->player || !data->exit
		|| !data->player_med || !data->player_end)
	{
		ft_putstr_fd("Error\nImage loading failed\n", 2);
		return (1);
	}
	return (0);
}

int	which_player(t_all *all, size_t i, size_t j)
{
	int	check;

	check = 0;
	if (all->game->collec_missing == all->game->items)
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->player, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->collec_missing >= (2 * all->game->items) / 3)
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->player_med, j * BITS_SIZE, i * BITS_SIZE);
	else
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->player_end, j * BITS_SIZE, i * BITS_SIZE);
	return (0);
}

int	fill_display(t_all *all, size_t i, size_t j)
{
	int	check;

	check = 0;
	if (all->game->map[i][j] == '1')
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->wall, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == '0' ||
			(all->game->map[i][j] == 'E' && (all->game->collec_missing != 0)))
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->floor, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == 'C')
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->colectible, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == 'P')
			check = which_player(all, i, j);
	else if (all->game->map[i][j] == 'E' && (all->game->collec_missing == 0))
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->exit, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == 'D')
		check = mlx_put_image_to_window(all->data->mlx, all->data->win,
				all->data->danger, j * BITS_SIZE, i * BITS_SIZE);
	else if (check != 0)
		return (1);
	return (0);
}

int	display_all(t_all *all)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (file_to_img(all->data))
		return (close_wind(all), 1);
	while (all->game->map[i])
	{
		j = 0;
		while (all->game->map[i][j])
		{
			if (fill_display(all, i, j))
				return (close_wind(all), 1);
			j++;
		}
		i++;
	}
	display_mouv(all);
	return (0);
}
