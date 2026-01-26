/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:56:45 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/26 18:24:11 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	struct_atribution(char **tab, t_game *game)
{
	game->row = ft_lentab(tab);
	game->cols = ft_strlen(tab[0]);
	game->player = check_count(tab, 'P');
	game->exit = check_count(tab, 'E');
	game->items = check_count(tab, 'C');
	find_pos_player(tab, game);
}

int	check_all(char **tab, t_game *game, char *av)
{
	(void)av;
	if (!check_map_format(av))
		return (free_tab(tab), write_error(1), free(game), 1);
	if (check_len_map(tab))
		return (free_tab(tab), write_error(2), free(game), 1);
	if (check_characters(tab))
		return (free_tab(tab), write_error(3), free(game), 3);
	if (game->player != 1 || game->exit != 1 || game->items < 1)
		return (free_tab(tab), write_error(4), free(game), 3);
	if (flood_fill(tab, game))
		return (free_tab(tab), write_error(5), free(game), 3);
	return (0);
}

void	find_pos_player(char **tab, t_game *game)
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
					game->pos_x = j;
					game->pos_y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_characters(char **tab)
{
	size_t	i;
	size_t	lentab;

	i = 1;
	lentab = ft_lentab(tab);
	if (is_one(tab[0]))
		return (1);
	while (i < lentab)
	{
		if (check_core(tab[i]))
			return (1);
		i++;
	}
	if (is_one(tab[lentab]))
		return (1);
	return (0);
}
