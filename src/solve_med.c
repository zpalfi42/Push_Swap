/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_med.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:02:27 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/24 15:27:54 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_small(t_ps *data)
{
	int	i;
	int	n;
	int	aux;

	i = 0;
	n = ft_atoi(data->a[0]);
	while (data->a[i] != NULL)
	{
		if (ft_atoi(data->a[i]) < n)
		{
			n = ft_atoi(data->a[i]);
			aux = i;
		}
		i++;
	}
	return (aux);
}

static void	move_to_start(t_ps *data)
{
	int	n;
	int	i;

	i = 0;
	n = find_small(data);
	while (data->a[i] != NULL)
		i++;
	if (n > (i / 2))
	{
		while (n != i)
		{
			rra(data, 1);
			n++;
		}
	}
	else
	{
		while (n > 0)
		{
			ra(data, 1);
			n--;
		}
	}
}

static int	put_in_middle(t_ps *data, int i)
{
	int	n;

	n = ft_atoi(data->a[i]);
	while (ft_atoi(data->a[0]) != n)
	{
		if (i < 2)
			ra(data, 1);
		else
			rra(data, 1);
	}
	pa(data);
	if (is_solved(data) != 1)
		move_to_start(data);
	return (0);
}

static int	move_to_ideal(t_ps *data)
{
	int	i;

	i = 0;
	while (data->a[i] != NULL && data->a[i + 1] != NULL)
	{
		if (ft_atoi(data->a[i]) < ft_atoi(data->b[0])
			&& ft_atoi(data->b[0]) < ft_atoi(data->a[i + 1]))
			return (put_in_middle(data, i + 1));
		i++;
	}
	pa(data);
	if (is_solved(data) != 1)
		move_to_start(data);
	return (0);
}

void	solve_med(t_ps *data)
{
	pb(data);
	if (data->argc == 6)
		pb(data);
	solve_easy(data);
	move_to_ideal(data);
	if (data->argc == 6)
		move_to_ideal(data);
}
