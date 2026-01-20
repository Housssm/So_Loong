/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 20:59:39 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/20 21:16:07 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	size_fd(int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		i += 1;
		free(str);
	}
	close (fd);
	return (i);
}

int	is_one(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\0' || str[i] == 10)
			break ;
		else if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_letter(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
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
		return (0);
	if (str[0] != '1' || str[len] != '1')
		return (1);
	while (i < len)
	{
		if (check_letter(str[i]))
			return (1);
		i++;
	}
	return (0);
}
