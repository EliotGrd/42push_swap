/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:34:55 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/07 04:32:42 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int	ft_atoi_safe(const char *nptr, int *valid)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (!nptr[i])
		return (nb);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] < 48 || nptr[i + 1] > 57)
			return (nb);
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		nb = (nb * 10) + (nptr[i++] - '0');
	if (nb * sign < INT_MIN || nb * sign > INT_MAX)
		*valid = 0;
	return (nb * sign);
}

static int	*parse_string(char *s, int *valid, int *size)
{
	int		i;
	int		*tab;
	char	**splitted;

	i = 0;
	splitted = ft_split(s, ' ');
	while (splitted[i])
		i++;
	tab = malloc(sizeof(int) * i);
	*size = i;
	i = 0;
	while (splitted[i])
	{
		tab[i] = ft_atoi_safe(splitted[i], valid);
		printf("[DEBUG] : %d ", tab[i]);
		i++;
	}
	printf("\n[DEBUG] : %d %d %d\n", tab[0], tab[1], tab[2]);
	return (tab);
}

static int	*parse_int(int ac, char **av, int *valid)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		tab[i] = ft_atoi_safe(av[i + 1], valid);
		ft_printf("[DEBUG] : %d ", tab[i]);
		i++;
	}
	printf("\n[DEBUG] : %d %d %d\n", tab[0], tab[1], tab[2]);
	return (tab);
}

static int	is_all_digit(char *s, int is_lst)
{
	int	i;

	i = 0;
	if (is_lst)
		while (s[i])
		{
			if (ft_isdigit(s[i]) == 0 && ft_iswspace(s[i]) == 0)
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
		*valid = 0;
	return (tab);
}
