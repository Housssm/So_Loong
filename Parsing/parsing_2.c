/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 19:13:18 by hoel-har          #+#    #+#             */
/*   Updated: 2026/01/22 20:02:37 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strrdup(const char *str, char c)
{
	char			*s;
	char			*dest;
	int				i;

	i = 0;
	s = (char *)str;
	dest = malloc(sizeof(char) * ft_strlen((const char *)s) + 1);
	if (dest == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			break ;
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**copy_tab(char **tab)
{
	size_t	i;
	size_t	size;
	char	**result;

	i = 0;
	size = ft_lentab(tab);
	result = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		result[i] = ft_strrdup(tab[i], 10);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	check_count(char **tab, char c)
{
	size_t	i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (i < ft_lentab(tab))
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

int	check_map_format(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b')
		return (1);
	return (0);
}

int	check_len_map(char **tab)
{
	size_t			i;
	size_t			len;
	static size_t	ref;

	i = 0;
	ref = ft_strlen(tab[0]);
	while (tab[i])
	{
		len = ft_strlen(tab[i]);
		if (len != ref)
		{
			return (1);
			break ;
		}
		i++;
	}
	if (ref * ft_lentab(tab) < 15)
		return (1);
	return (0);
}
