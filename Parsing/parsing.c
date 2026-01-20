/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:56:45 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/20 21:12:54 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**extract_map(int ac, char **av)
{
	int				fd;
	int				j;
	int				len_fd;
	char			**tab;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	len_fd = size_fd(fd);
	fd = open(av[1], O_RDONLY);
	j = 0;
	tab = malloc(sizeof(char *) * (len_fd + 1));
	if (!tab)
		return (free(tab), NULL);
	while (1)
	{
		tab[j] = get_next_line(fd);
		if (tab[j] == NULL)
			break ;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int	check_all(char **tab)
{
	if (check_len_map(tab))
		return (free_tab(tab), 1);
	if (check_characters(tab))
		return (free_tab(tab), 2);
	if (check_doublons(tab))
		return (free_tab(tab), 3);
	//if floodfill
	return (0);
}

int	check_doublons(char **tab)
{
	size_t	i;
	int		j;
	int		counte;
	int		countp;

	i = 0;
	counte = 0;
	countp = 0;
	while (i < ft_lentab(tab))
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				countp += 1;
			if (tab[i][j] == 'E')
				counte += 1;
			j++;
		}
		i++;
	}
	if (counte != 1 || countp != 1)
		return (1);
	return (0);
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
