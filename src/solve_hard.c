/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:44:33 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/24 14:43:01 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	put_mid_b_count(t_ps *data, int i)
{
	int	j;

	j = 0;
	while (data->b[j] != NULL)
		j++;
	if (i < (j / 2))
		return (i);
	else
		return (j - i);
}

static int	n_moves(t_ps *data, int mode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->a[j + 1] != NULL)
		j++;
	j /= 2;
	while (data->b[i] != NULL && data->b[i + 1] != NULL)
	{
		if (ft_atoi(data->b[i]) > ft_atoi(data->a[mode])
			&& ft_atoi(data->a[mode]) > ft_atoi(data->b[i + 1]))
			return (put_mid_b_count(data, i + 1) + i_or_j(mode, j));
		i++;
	}
	if (ft_atoi(data->b[0]) < ft_atoi(data->a[mode])
		&& ft_atoi(data->a[mode]) < ft_atoi(data->b[i]))
		return (i_or_j(mode, j));
	else if (rev_sort(data) != 1)
		return (put_mid_b_count(data, find_big(data)) + i_or_j(mode, j));
	return (i_or_j(mode, j));
}

static void	move_to_i(t_ps *data, int i)
{
	int	aux;
	int	j;

	j = 0;
	while (data->a[j + 1] != NULL)
		j++;
	j /= 2;
	aux = ft_atoi(data->a[i]);
	while (ft_atoi(data->a[0]) != aux)
	{
		if (i < j)
			ra(data, 1);
		else
			rra(data, 1);
	}
}

static void	best_b(t_ps *data)
{
	int	i;
	int	aux;
	int	auxi;

	i = 0;
	auxi = 0;
	aux = n_moves(data, i);
	while (data->a[i] != NULL)
	{
		if (n_moves(data, i) < aux)
		{
			aux = n_moves(data, i);
			auxi = i;
		}
		i++;
	}
	move_to_i(data, auxi);
	move_b(data);
}

void	solve_hard(t_ps *data)
{
	pb(data);
	pb(data);
	while (data->a[0] != NULL)
		best_b(data);
	if (rev_sort(data) != 1)
		move_rev(data);
	while (data->b[0] != NULL)
		pa(data);
}
