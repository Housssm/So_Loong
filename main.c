/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:10:00 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/19 18:03:53 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_one(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\0' || str[i] == 10)
			break;
		else if ( str[i] != '1')
			return(1); // error
		i++;
	}
	return (0);
}

int	check_letter(char c)
{
	if ( c != '1' && c != '0' && c != 'C'&& c != 'E' && c != 'P' )
		return (1);
	else
		return (0);
}

int	check_core(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str) - 2; // -2 car 000111 + '\n' + '\0';
	i = 1;
	if (!str)
		return 0;
	if (str[0] != '1' || str[len] != '1')
		return (1); // error
	while (i < len)
	{
		if (check_letter(str[i]))
			return (1); // error
		i++;
	}
	printf("%d\n", i);
	return (0);
}


int	size_fd(int fd)
{
	char	*str;
	int i;
	
	str = get_next_line(fd);
	i = 1;
	while (fd > 0)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		i++;
	}
	close(fd);
	return (i);
}

int	main(int ac, char **av)
{
	(void)ac;
	int		fd = open(av[1], O_RDONLY);
	char	*str = get_next_line(fd);	
	int len = size_fd(fd);
	int j = 0;
	char **tab;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return 0;
	while (fd > 0)
	{
		tab[j] = str;
		j++;
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break;
	}
	close(fd);
	int i = 0 ;
	while (str[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}