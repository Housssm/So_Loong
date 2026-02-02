/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:19:15 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/02 08:37:21 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_check(char c)
{
	if (c == 'C' || c == 'P' || c == 'E' || c == '0')
		return (1);
	else if (c == 1)
		return (0);
	return (0);
}

void	flood_file_check(char **copy_map, int x, int y)
{
	if (flood_check(copy_map[x][y]))
	{
		copy_map[x][y] = 'O';
		flood_file_check(copy_map, x, y + 1);
		flood_file_check(copy_map, x, y - 1);
		flood_file_check(copy_map, x + 1, y);
		flood_file_check(copy_map, x - 1, y);
	}
}

int	flood_invalid(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C' || tab[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_fill(char **tab, t_all *all)
{
	char	**copy_map;

	copy_map = NULL;
	copy_map = copy_tab(tab);
	flood_file_check(copy_map, all->data->pos_y, all->data->pos_x);
	if (flood_invalid(copy_map))
		return (free_tab(copy_map), 1);
	free_tab(copy_map);
	return (0);
}

void	write_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Error: Check map's format\n", 1);
	if (i == 2)
		ft_putstr_fd("Error: Check map's dimension\n", 1);
	if (i == 3)
		ft_putstr_fd("Error: Check map formation\n", 1);
	if (i == 4)
		ft_putstr_fd("Error: Check number of variable\n", 1);
	if (i == 5)
		ft_putstr_fd("Error : Unreachable item\n", 1);
	if (i == 6)
		ft_putstr_fd("Error : Try smaller map\n", 1);
}
