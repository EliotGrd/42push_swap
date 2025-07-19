/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraud <egiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:36:40 by egiraud           #+#    #+#             */
/*   Updated: 2025/07/19 19:40:28 by egiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*shell_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	gap;

	i = 0;
	gap = size / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			tmp = tab[i];
			j = i;
			while (j >= gap && tab[j - gap] > tmp)
			{
				tab[j] = tab[j - gap];
				j -= gap;
			}
			tab[j] = tmp;
			i++;
		}
		gap /= 2;
	}
	return (tab);
}

void	split_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_atoi_safe_suite(const char *nptr, int i, int sign, int *valid)
{
	long	nb;

	nb = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		if (((nb * 10) + (nptr[i] - '0')) * sign < INT_MIN || ((nb * 10)
				+ (nptr[i] - '0')) * sign > INT_MAX)
			*valid = 0;
		nb = (nb * 10) + (nptr[i++] - '0');
	}
	return (nb * sign);
}

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
	nb = ft_atoi_safe_suite(nptr, i, sign, valid);
	return (nb);
}
