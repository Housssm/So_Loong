/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:11 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/22 20:05:51 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "GNL/get_next_line.h"

typedef	struct s_game
{
	int		pos_x;
	int		pos_y;
	int		player;
	int		exit;
	int		row;
	int		cols;
	int		items;
	int		recheable;
	
}t_game;

typedef struct s_map
{
	char	**tab;
	char		**recheable;
	
}t_map;


//Parsing
char	**extract_map(char **av);
int		check_all(char **tab, t_game *game, char *av);
int		check_count(char **tab, char c);
void	find_pos_player(char **tab, t_game *game);
int		check_characters(char **tab);
int		check_len_map(char **tab);
int		is_one(char *str);
int		check_letter(char c);
int		check_core(char *str);
int		size_fd(int fd);
void	struct_atribution(char **tab, t_game *game);
int		flood_fill(char **tab, t_game *game);
int		flood_invalid(char **tab);
void	flood_file_check(char **copy_map, int x, int y);
int	check_map_format(char *av);
void	write_error(int	i);



//Cleaning
void	free_tab(char **tab);

// Utils
char	**copy_tab(char **tab);
size_t	ft_lentab(char **tab);
char	*ft_strrdup(const char *str, char c);

#endif