/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_comands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:40:06 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/15 12:49:58 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *data)
{
	char	*temp;

	temp = data->a[0];
	data->a[0] = data->a[1];
	data->a[1] = temp;
	write(1, "sa\n", 3);
}
