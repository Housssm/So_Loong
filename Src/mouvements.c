/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:09:02 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/02 11:08:25 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_mouv(t_all *all)
{
	char	*mouv;

	mouv = ft_itoa(all->data->nb_mouv);
	if (!mouv)
		return ;
	mlx_string_put(all->data->mlx, all->data->win, 10,
		20, 0xFFFFFF, "Items left: ");
	mlx_string_put(all->data->mlx, all->data->win, 100, 20, 0xFFFFFF, mouv);
	free(mouv);
}

void	bring_back_exit(t_all *all)
{
	int	x;
	int	y;

	y = all->data->pos_ex_y;
	x = all->data->pos_ex_x;
	if (all->game->collec_missing == 0)
		all->game->map[y][x] = 'E';
}

int	player_mouvement(t_all *all, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = all->data->pos_x;
	pos_y = all->data->pos_y;
	if (all->game->map[pos_y + y][pos_x + x] != '1')
	{
		if (all->game->map[pos_y + y][pos_x + x] == 'C')
			all->game->collec_missing -= 1;
		else if (all->game->map[pos_y + y][pos_x + x] == 'E' &&
				all->game->collec_missing == 0)
			return (1);
		else if (all->game->map[pos_y + y][pos_x + x] == 'D')
			return (404);
		all->game->map[pos_y + y][pos_x + x] = 'P';
		all->game->map[pos_y][pos_x] = '0';
		all->data->pos_x += x;
		all->data->pos_y += y;
		all->data->nb_mouv += 1;
		if (all->game->collec_missing == 0)
			bring_back_exit(all);
	}
	delete_all_image(all->data);
	display_all(all);
	return (0);
}

int	key_pressed(int touch, t_all *all)
{
	int	win;
	int	count;

	win = 0;
	count = 0;
	if (touch == ESC)
		close_wind(all);
	else if (touch == RIGHT)
		win = player_mouvement(all, 1, 0);
	else if (touch == LEFT)
		win = player_mouvement(all, -1, 0);
	else if (touch == UP)
		win = player_mouvement(all, 0, -1);
	else if (touch == DOWN)
		win = player_mouvement(all, 0, 1);
	if (win == 1 || win == 404)
	{
		if (win == 1)
			ft_putstr_fd("Victory\n", 1);
		else if (win == 404)
			ft_putstr_fd("You've been caught.", 1);
		close_wind(all);
	}
	return (0);
}
