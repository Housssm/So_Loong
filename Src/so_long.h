/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:11 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/29 21:50:14 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../GNL/get_next_line.h"
#include "../minilibx-linux/mlx.h"



#  define WIND_NAME "So-long"
#  define CLOSE_MOUSE 17
#  define BITS_SIZE 64
#  define DIM_X 750
#  define DIM_Y 400
#  define IMG_WALL "Images/wall_bank.xpm"
#  define IMG_FLOOR "Images/floor_bank.xpm"
#  define IMG_COLL "Images/money.xpm"
#  define IMG_PLAYER "Images/Robber_beg.xpm"
#  define IMG_PLAYER2 "Images/Robber_med.xpm"
#  define IMG_PLAYER3 "Images/Robber_end.xpm"
#  define IMG_EXIT "Images/exit.xpm"
#  define IMG_DANG "Images/police.xpm"
#  define MAX_WIDTH 1280
#  define MAX_HEIGHT 720
#  define ESC 65307
#  define RIGHT 100
#  define LEFT 97
#  define UP 119
#  define DOWN 115



typedef	struct s_game
{
	int		player;
	int		exit;
	int		row;
	int		cols;
	int		items;
	int		collected;
	int		collec_missing;
	int		exit_open;
	char	**map;
}t_game;

// typedef struct s_images
// {
// 	void	*wall;
// 	void	*floor;
// 	void	*player;
// 	void	*colectibles;
// 	void	*first_exit;
// 	void	*exit;
// }t_images;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*colectible;
	int		pos_x;
	int		pos_y;
	int		tile_size;
	void	*player;
	void	*player_med;
	void	*player_end;
	void	*exit;
	void	*floor;
	void	*danger;
	int		w;
	int		h;
	// t_images	images;
}t_data;

typedef struct s_all
{
	t_game	*game;	
	t_data	*data;	
}t_all;


//Parsing
char	**extract_map(char **av);
int		check_all(char **tab, t_all *all);
int		check_count(char **tab, char c);
void	find_pos_player(char **tab, t_all *all);
int		check_characters(char **tab);
int		check_len_map(char **tab);
int		is_one(char *str);
int		check_letter(char c);
int		check_core(char *str);
int		size_fd(int fd);
void	struct_atribution(char **tab, t_all *all);
int		flood_fill(char **tab, t_all *all);
int		flood_invalid(char **tab);
void	flood_file_check(char **copy_map, int x, int y);
int	check_map_format(char *av);
void	write_error(int	i);
int	first_check(char **tab);


//Game
int	wind_creation(t_all *all);
int	file_to_img(t_data	*data);
int	fill_display(t_all *all, size_t i, size_t j);
int	display_all(t_all *all);


//Cleaning
void	free_tab(char **tab);
int	close_wind(t_all *all);
int	delete_all_image(t_data *data);

// Utils
char	**copy_tab(char **tab);
size_t	ft_lentab(char **tab);
char	*ft_strrdup(const char *str, char c);
void	remove_newline(char **tab);

#endif
