/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:01:26 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/02 08:24:38 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_lentab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	remove_newline(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\n')
				tab[i][j] = '\0';
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
