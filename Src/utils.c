/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:01:26 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 11:24:37 by hoel-har         ###   ########.fr       */
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
			if ( tab[i][j] == '\n')
				tab[i][j] = '\0';
			j++;
		}
		i++;
	}
}
