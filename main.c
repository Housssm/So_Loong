/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/22 19:54:12 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac , char **av)\
{
	(void)ac;
	char **tab;
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	tab = extract_map(av);
	struct_atribution(tab, game);
	if (check_all(tab, game, av[1])) // Je free ici en cas derreur 
		return (1); 
	int i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);		
		i++;
	}
	free_tab(tab);
	free(game);
	return (0);
}
