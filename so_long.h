/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:11 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/26 17:19:18 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "GNL/get_next_line.h"
#include "mlx.h"



#  define WIND_NAME "So-long"
#  define CLOSE_MOUSE 17
#  define BITS_SIZE 64
#  define DIM_X 750
#  define DIM_Y 400

typedef	struct s_game
{
	int		pos_x;
	int		pos_y;
	int		player;
	int		exit;
	int		row;
	int		cols;
	int		items;
	int		collected;
	int		exit_open;
	char	**map;
	
}t_game;

typedef struct s_images
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*colectibles;
	void	*first_exit;
	void	*exit;
}t_images;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*colectible;
	void	*player;
	void	*exit;
	void	*floor;
	int		w;
	int		h;
	t_images	images;
}t_data;

typedef struct s_all
{
	t_game	*game;	
	t_data	*data;	
}t_all;



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
void	remove_newline(char **tab);

#endif