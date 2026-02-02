/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:56:45 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/02 08:23:34 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**extract_map(char **av)
{
	int				fd;
	int				j;
	int				len_fd;
	char			**tab;

	fd = open(av[1], O_RDONLY);
	len_fd = size_fd(fd);
	fd = open(av[1], O_RDONLY);
	j = 0;
	tab = malloc(sizeof(char *) * (len_fd + 1));
	if (!tab)
		return (free_tab(tab), NULL);
	while (1)
	{
		tab[j] = get_next_line(fd);
		if (tab[j] == NULL)
			break ;
		j++;
	}
	tab[j] = NULL;
	remove_newline(tab);
	return (tab);
}

void	struct_atribution(char **tab, t_all *all)
{
	all->game->row = ft_lentab(tab);
	all->game->cols = ft_strlen(tab[0]);
	all->game->player = check_count(tab, 'P');
	all->game->exit = check_count(tab, 'E');
	all->game->items = check_count(tab, 'C');
	all->game->collec_missing = all->game->items;
	all->data->nb_mouv = 0;
	all->data->player = NULL;
	all->data->player_med = NULL;
	all->data->player_end = NULL;
	all->data->floor = NULL;
	all->data->wall = NULL;
	all->data->floor = NULL;
	all->data->exit = NULL;
	all->data->danger = NULL;
	all->data->colectible = NULL;
	find_pos_player(tab, all);
}

int	first_check(char **tab)
{
	if (check_len_map(tab))
		return (free_tab(tab), write_error(2), 1);
	if (check_characters(tab))
		return (free_tab(tab), write_error(3), 3);
	return (0);
}

int	check_all(char **tab, t_all *all)
{
	if (check_len_map(tab))
		return (free_tab(tab), write_error(2), 1);
	if (check_characters(tab))
		return (free_tab(tab), write_error(3), 3);
	if (all->game->player != 1 || all->game->exit != 1 || all->game->items < 1)
		return (free_tab(tab), write_error(4), 3);
	if (flood_fill(tab, all))
		return (free_tab(tab), write_error(5), 3);
	return (0);
}

void	find_pos_player(char **tab, t_all *all)
{
	size_t	i;
	int		j;	

	i = 0;
	while (i < ft_lentab(tab))
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
					all->data->pos_x = j;
					all->data->pos_y = i;
			}
			j++;
		}
		i++;
	}
}
