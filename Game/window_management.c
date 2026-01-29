/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:28:38 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 10:53:46 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	wind_creation(t_data	*data, t_game *game)
{
	int	width;
	int	height;

	width = game->cols * BITS_SIZE;
	height = game->row * BITS_SIZE;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (free(data->mlx), 1);
	data->win = mlx_new_window(data->mlx, width, height, WIND_NAME);
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
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
	data->exit = mlx_xpm_file_to_image(data->mlx, IMG_EXIT, &data->w, &data->h);
	if (!data->wall || !data->floor || !data->colectible
		|| !data->player || !data->exit)
		return (1);
	return (0);
}

void	fill_display(t_all *all, size_t i, size_t j)
{
	if (all->game->map[i][j] == '1')
		mlx_put_image_to_window(all->data->mlx, all->data->win,
			all->data->wall, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == '0')
		mlx_put_image_to_window(all->data->mlx, all->data->win,
			all->data->floor, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == 'C')
		mlx_put_image_to_window(all->data->mlx, all->data->win,
			all->data->colectible, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == 'P')
		mlx_put_image_to_window(all->data->mlx, all->data->win,
			all->data->player, j * BITS_SIZE, i * BITS_SIZE);
	else if (all->game->map[i][j] == 'E')
		mlx_put_image_to_window(all->data->mlx, all->data->win,
			all->data->exit, j * BITS_SIZE, i * BITS_SIZE);
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
			fill_display(all, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
