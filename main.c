/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/20 21:01:45 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	is_one(char *str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\0' || str[i] == 10)
// 			break;
// 		else if ( str[i] != '1')
// 			return(1); // error
// 		i++;
// 	}
// 	return (0);
// }

// int	check_letter(char c)
// {
// 	if ( c != '1' && c != '0' && c != 'C'&& c != 'E' && c != 'P' )
// 		return (1);
// 	else
// 		return (0);
// }

// int	check_core(char *str)
// {
// 	int	i;
// 	int	len;

// 	len = ft_strlen(str) - 2; // -2 car 000111 + '\n' + '\0';
// 	i = 1;
// 	if (!str)
// 		return 0;
// 	if (str[0] != '1' || str[len] != '1')
// 		return (1); // error
// 	while (i < len)
// 	{
// 		if (check_letter(str[i]))
// 			return (1); // error
// 		i++;
// 	}
	
// 	return (0);
// }


// int	size_fd(int fd)
// {
// 	int		i;
// 	char	*str;
	
// 	i = 0;
// 	while(1)
// 	{
// 		str = get_next_line(fd);
// 		if ( str == NULL)
// 			break;
// 		i += 1;
// 		free(str);
// 	}
// 	close (fd);
// 	return (i);	
// }

// void	free_tab(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// }

// char	**extract_map(int ac, char **av)
// {
// 	int 			fd;
// 	int				j;
// 	int				len_fd;
// 	char			**tab;

// 	(void)ac;
// 	fd = open(av[1], O_RDONLY);
// 	len_fd = size_fd(fd);
// 	fd = open(av[1], O_RDONLY);
// 	j = 0;

// 	tab = malloc(sizeof(char *) * (len_fd + 1));
// 	if (!tab)
// 		return (free(tab),NULL);
// 	while(1)
// 	{
// 		tab[j] = get_next_line(fd);
// 		if (tab[j] == NULL)
// 			break;
// 		j++;
// 	}
// 	tab[j] = NULL;
// 	return (tab);
// }

// int	check_len_map(char **tab)
// {
// 	size_t			i;
// 	size_t			len;
// 	static size_t	ref;

// 	i = 0;
// 	ref = ft_strlen(tab[0]);
// 	while (tab[i])
// 	{
		
// 		len = ft_strlen(tab[i]);
// 		if (len != ref)
// 		{
// 			return(1);
// 			break;
// 		}
// 		i++;
// 	}
// 	if ( ref * ft_lentab(tab) < 15)
// 		return (1);
// 	return (0);
// }

// size_t	ft_lentab(char **tab)
// {
// 	size_t	i;
	
// 	i = 0;
// 	while(tab[i])
// 		i++;
// 	return (i);
// }

// int	check_characters(char **tab)
// {
// 	size_t	i;
// 	size_t	lentab;
	
// 	i = 1;
// 	lentab = ft_lentab(tab);
// 	if (is_one(tab[0]))
// 		return (1);
// 	while(i < lentab)
// 	{
// 		if (check_core(tab[i]))
// 			return (1);
// 		i++;
// 	}
// 	if ( is_one(tab[lentab]))
// 		return (1);	
// 	return (0);
// }
// int	check_doublons(char **tab)
// {
// 	size_t	i;
// 	int		j;
// 	int		countE;
// 	int		countP;
	
// 	i = 0;
// 	countE = 0;
// 	countP = 0;
// 	while ( i < ft_lentab(tab))
// 	{
// 		j = 0;
// 		while (tab[i][j])
// 		{
// 			if (tab[i][j] == 'P')
// 				countP += 1;
// 			if (tab[i][j] == 'E')
// 				countE += 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	printf("count e = %d, count p = %d\n", countE, countP );
// 	if ( countE != 1 || countP !=1)
// 			return (1);
// 	return (0);
// }

// int	check_all(char **tab)
// {

// 	if (check_len_map(tab))
// 		return (free_tab(tab), 1);
// 	if ( check_characters(tab))
// 		return (free_tab(tab), 2);
// 	if ( check_doublons(tab))
// 		return (free_tab(tab), 3);
// 	//if floodfill
// 	return (0);
// }

int main(int ac , char **av)\
{
	char **tab;

	tab = extract_map(ac, av);
	if (check_all(tab)) // Je free ici en cas derreur 
		return ( write(1, "Error\n",6), 1); 
	int i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	free_tab(tab);
	return (0);
}