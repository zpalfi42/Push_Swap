/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_med_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:57:02 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/24 13:20:22 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_solved(t_ps *data)
{
	int	i;

	i = 0;
	while (data->a[i] != NULL && data->a[i + 1] != NULL)
	{
		if (ft_atoi(data->a[i]) > ft_atoi(data->a[i + 1]))
			return (-1);
		i++;
	}
	return (1);
}
