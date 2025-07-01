/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:55 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/01 18:27:07 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*parse_string(char *s)
{
	int		i;
	int		*tab;
	char	**splitted;

	i = 0;
	splitted = ft_split(s, ' ');
	while (splitted[i])
		i++;
	tab = malloc(sizeof(int) * i);
	i = 0;
	while (splitted[i])
	{
		tab[i] = ft_atoi(splitted[i]);
		i++;
	}
	return tab;
}

static int	*parse_int(int ac, char **av)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		tab[i] = ft_atoi(av[i]);
		ft_printf("%d", tab[i]);
		i++;
	}
	return tab;
}

static int	is_all_digit(char *s, int is_lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (is_lst)
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 0 || ft_iswspace(s[i]) == 0)
				return (0);
			i++;
		}
	else
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 0)
				return (0);
			i++;
		}
	return (1);
}

void	parsing(int ac, char **av)
{
	int	i;
	int	*tab;

	i = 0;
	tab = NULL;
	if (ac == 2)
	{
		if (is_all_digit(av[1], 1))
			tab = parse_string(av[1]);
		else
			ft_printf("Error");
	}
	else if (ac > 2)
	{
		while (++i < ac)
		{
			if (is_all_digit(av[i], 0) == 0)
			{
				ft_printf("Error");
				return;
			}
		}
		parse_int(ac, av);
	}
	else
		ft_printf("Error");
	ft_printf("%d %d %d\n", tab[0], tab[1], tab[2]);
}
