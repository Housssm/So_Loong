/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/21 21:43:49 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	struct_atribution(char **tab)
// {
// 	t_game	*game;
// 	game->row = ft_lentab(tab);
// 	game->cols = ft_strlen(tab[0]);
// 	game->player = check_count(tab, 'P');
// 	game->exit = check_count(tab, 'E');
// 	game->items = check_count(tab, 'C');	
// }




int main(int ac , char **av)\
{
	(void)ac;
	char **tab;
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	tab = extract_map(av);
	struct_atribution(tab, game) ;
	if (check_all(tab, game)) // Je free ici en cas derreur 
		return ( write(1, "Error\n",6), 1); 
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