/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_easy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:27:52 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/24 15:28:27 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_atoi(t_ps *data)
{
	int	i;

	data->aint = (int *)malloc(sizeof(int) * (data->argc));
	if (!data->aint)
		error("Error: Failed stack int malloc\n");
	i = 0;
	while (data->a[i] != NULL)
	{
		data->aint[i] = ft_atoi(data->a[i]);
		i++;
	}
}

static int	get_easy_mode(t_ps *data)
{
	if (data->aint[0] < data->aint[1] && data->aint[1] > data->aint[2]
		&& data->aint[0] < data->aint[2])
		return (1);
	else if (data->aint[0] < data->aint[1] && data->aint[1] > data->aint[2]
		&& data->aint[0] > data->aint[2])
		return (2);
	else if (data->aint[0] > data->aint[1] && data->aint[0] < data->aint[2])
		return (3);
	else if (data->aint[0] > data->aint[1] && data->aint[0] > data->aint[2]
		&& data->aint[1] < data->aint[2])
		return (4);
	else if (data->aint[0] > data->aint[1] && data->aint[0] > data->aint[2]
		&& data->aint[1] > data->aint[2])
		return (5);
	return (0);
}

void	solve_easy(t_ps *data)
{
	stack_atoi(data);
	if (get_easy_mode(data) == 1)
	{
		sa(data);
		ra(data, 1);
	}
	else if (get_easy_mode(data) == 2)
		rra(data, 1);
	else if (get_easy_mode(data) == 3)
		sa(data);
	else if (get_easy_mode(data) == 4)
		ra(data, 1);
	else if (get_easy_mode(data) == 5)
	{
		ra(data, 1);
		sa(data);
	}
}
