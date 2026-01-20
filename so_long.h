/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:08:11 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/20 21:03:44 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "GNL/get_next_line.h"

// typedef	ligne
// {
// 	char	*content;
// 	int		pos;
// 	int		len;
// }

//Parsing
char	**extract_map(int ac, char **av);
int	check_all(char **tab);
int	check_doublons(char **tab);
int	check_characters(char **tab);
int	check_len_map(char **tab);
int	is_one(char *str);
int	check_letter(char c);
int	check_core(char *str);
int	size_fd(int fd);



//Cleaning
void	free_tab(char **tab);

// Utils
size_t	ft_lentab(char **tab);

#endif