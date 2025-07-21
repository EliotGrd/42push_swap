/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:55 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/19 19:40:44 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*parse_string(char *s, int *valid, int *size)
{
	int		i;
	int		*tab;
	char	**splitted;

	i = 0;
	splitted = ft_split(s, ' ');
	if (!splitted)
		return (NULL);
	while (splitted[i])
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
	{
		*valid = 0;
		return (NULL);
	}
	*size = i;
	i = 0;
	while (splitted[i])
	{
		tab[i] = ft_atoi_safe(splitted[i], valid);
		i++;
	}
	split_free(splitted);
	return (tab);
}

static int	*parse_int(int ac, char **av, int *valid)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
	{
		*valid = 0;
		return (NULL);
	}
	while (i < ac - 1)
	{
		tab[i] = ft_atoi_safe(av[i + 1], valid);
		i++;
	}
	return (tab);
}

static int	is_all_digit_lst(char *s)
{
	int	i;
	int	contain_digit;

	i = -1;
	contain_digit = 0;
	while (s[++i])
		if (ft_isdigit(s[i]))
			contain_digit = 1;
	if (contain_digit == 0)
		return (0);
	i = -1;
	if (s[0] == '-')
		i++;
	while (s[++i])
	{
		if ((ft_isdigit(s[i]) == 0 && ft_iswspace(s[i]) == 0 && s[i] != '-')
			|| (s[i] == '-' && s[i - 1] != ' '))
			return (0);
		if (s[i] == '-' && !ft_isdigit(s[i + 1]))
			return (0);
	}
	return (1);
}

static int	is_all_digit(char *s, int is_lst)
{
	int	i;

	i = -1;
	if (is_lst)
	{
		if (is_all_digit_lst(s) == 0)
			return (0);
	}
	else
	{
		if (s[0] == '\0')
			return (0);
		while (s[++i])
		{
			if ((ft_isdigit(s[i]) == 0 && s[i] != '-') || (s[i] == '-'
					&& ft_isdigit(s[i - 1])))
				return (0);
			if (s[i] == '-' && !ft_isdigit(s[i + 1]))
				return (0);
		}
	}
	return (1);
}

int	*parsing(int ac, char **av, int *size, int *valid)
{
	int	i;
	int	*tab;

	i = 0;
	tab = NULL;
	if (ac == 2)
	{
		if (is_all_digit(av[1], 1))
			tab = parse_string(av[1], valid, size);
		else
			*valid = 0;
	}
	else if (ac > 2)
	{
		while (++i < ac)
		{
			if (is_all_digit(av[i], 0) == 0)
				*valid = 0;
		}
		tab = parse_int(ac, av, valid);
		*size = ac - 1;
	}
	else
		exit(0);
	return (tab);
}
