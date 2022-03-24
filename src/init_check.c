/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpalfi <zpalfi@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:12:34 by zpalfi            #+#    #+#             */
/*   Updated: 2022/03/24 15:22:08 by zpalfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_n(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '-')
		i++;
	while (n[i] != '\0')
	{
		if (!ft_isdigit(n[i]))
			return (0);
		i++;
	}
	if (ft_atoi(n) < 2147483648 && ft_atoi(n) > -2147483648)
		return (1);
	return (0);
}

static int	check_non_repeated(char **argv, char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == ft_atoi(s))
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	return (1);
}

static void	init_stack_a(t_ps *data, char **argv)
{
	int	i;

	data->a = (char **)malloc(sizeof(char *) * (data->argc));
	data->b = (char **)malloc(sizeof(char *));
	if (!data->a || !data->b)
		error("Error: Failed stack malloc\n");
	i = 1;
	while (argv[i])
	{
		data->a[i - 1] = argv[i];
		i++;
	}
	data->a[i - 1] = NULL;
	data->b[0] = NULL;
}

int	check_argv(t_ps *data, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (!check_n(argv[i]) || !check_non_repeated(argv, argv[i]))
			error("Error\n");
		i++;
	}
	init_stack_a(data, argv);
	return (1);
}
