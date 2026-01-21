/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:56:45 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/21 21:47:20 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**extract_map(char **av)
{
	int				fd;
	int				j;
	int				len_fd;
	char			**tab;
	char			**result;

	fd = open(av[1], O_RDONLY);
	len_fd = size_fd(fd);
	fd = open(av[1], O_RDONLY);
	j = 0;
	result = ((tab = malloc(sizeof(char *) * (len_fd + 1))));
	if (!tab || !result)
		return (free(tab), free(result), NULL);
	while (1)
	{
		tab[j] = get_next_line(fd);
		if (tab[j] == NULL)
			break ;
		j++;
	}
	tab[j] = NULL;
	result = copy_tab(tab);
	free_tab(tab);
	return (result);
}

void	struct_atribution(char **tab, t_game *game)
{
	//  me *)malloc(sizeof(t_game));
	game->row = ft_lentab(tab);
	game->cols = ft_strlen(tab[0]);
	game->player = check_count(tab, 'P');
	game->exit = check_count(tab, 'E');
	game->items = check_count(tab, 'C');
	find_pos_player(tab, game);
	// free(game);
	// return(game);
}

int	check_all(char **tab, t_game *game)
{

	// game = struct_atribution(tab);
	if (check_len_map(tab))
		return (free_tab(tab), free(game), 1);
	if (check_characters(tab))
		return (free_tab(tab), free(game), 2);
	if (game->player != 1 || game->exit !=1 || game->items < 1)
		return (free_tab(tab), free(game), 3);
	//if floodfill
	// printf("x = %d, y = %d\n", game->pos_x, game->pos_y);
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
					game->pos_x = i;
					game->pos_y = j;
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

int	check_len_map(char **tab)
{
	size_t			i;
	size_t			len;
	static size_t	ref;

	i = 0;
	ref = ft_strlen(tab[0]);
	while (tab[i])
	{
		len = ft_strlen(tab[i]);
		if (len != ref)
		{
			return (1);
			break ;
		}
		i++;
	}
	if (ref * ft_lentab(tab) < 15)
		return (1);
	return (0);
}
