/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_hard_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:29:03 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/24 14:41:27 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big(t_ps *data)
{
	int	i;
	int	n;
	int	aux;

	i = 0;
	n = ft_atoi(data->b[0]);
	while (data->b[i] != NULL)
	{
		if (ft_atoi(data->b[i]) > n)
		{
			n = ft_atoi(data->b[i]);
			aux = i;
		}
		i++;
	}
	return (aux);
}

void	move_rev(t_ps *data)
{
	int	n;
	int	i;

	i = 0;
	n = find_big(data);
	while (data->b[i] != NULL)
		i++;
	if (n > (i / 2))
		while (n++ != i)
			rrb(data, 1);
	else
		while (n-- > 0)
			rb(data, 1);
}

int	rev_sort(t_ps *data)
{
	int	i;

	i = 0;
	while (data->b[i] != NULL && data->b[i + 1] != NULL)
	{
		if (ft_atoi(data->b[i]) < ft_atoi(data->b[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

static int	put_mid_b(t_ps *data, int i)
{
	int	n;
	int	j;

	n = ft_atoi(data->b[i]);
	j = 0;
	while (data->b[j] != NULL)
		j++;
	j /= 2;
	while (ft_atoi(data->b[0]) != n)
	{
		if (i <= j)
			rb(data, 1);
		else
			rrb(data, 1);
	}
	return (pb(data));
}

int	move_b(t_ps *data)
{
	int	i;

	i = 0;
	while (data->b[i] != NULL && data->b[i + 1] != NULL)
	{
		if (ft_atoi(data->b[i]) > ft_atoi(data->a[0])
			&& ft_atoi(data->a[0]) > ft_atoi(data->b[i + 1]))
			return (put_mid_b(data, i + 1));
		i++;
	}
	if (ft_atoi(data->b[0]) < ft_atoi(data->a[0])
		&& ft_atoi(data->a[0]) < ft_atoi(data->b[i]))
		return (pb(data));
	else if (rev_sort(data) != 1)
		move_rev(data);
	return (pb(data));
}
