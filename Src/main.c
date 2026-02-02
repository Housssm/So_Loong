/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/02/02 08:38:04 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_data		data;
	t_all		all;

	if (ac == 1 || !av[1] || av[1][0] == 0 || !check_map_format(av[1]))
		return (ft_putstr_fd("Missing Map\n", 1), 1);
	all.data = &data;
	all.game = &game;
	game.map = extract_map(av);
	if (first_check(game.map))
		return (1);
	struct_atribution(game.map, &all);
	if (check_all(all.game->map, &all))
		return (1);
	if (wind_creation(&all))
		return (1);
	if (display_all(&all))
		return (1);
	mlx_hook(all.data->win, 2, 1L << 0, key_pressed, &all);
	mlx_hook((&data)->win, CLOSE_MOUSE, 0, close_wind, &all);
	mlx_loop((&data)->mlx);
	return (0);
}
