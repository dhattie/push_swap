/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:48:39 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:48:41 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_index_points(int koll_arg)
{
	int	point;

	point = 0;
	if (koll_arg <= 10)
		point = 2;
	else if (koll_arg <= 50)
		point = 5;
	else if (koll_arg <= 110)
		point = 15;
	else if (koll_arg > 110)
		point = 25;
	return (point);
}

void	ft_push_back(t_stack **a, t_stack **b, int stack_size)
{
	int	max_index;
	int	check_mediana;

	while (*b)
	{
		max_index = ft_find_max_index(*b);
		check_mediana = ft_check_mediana(b, max_index, stack_size);
		if ((*b)->index != max_index && !check_mediana)
		{
			ft_rotate_stack(b);
			ft_putstr_fd("rb\n", 1);
		}
		else if ((*b)->index != max_index && check_mediana)
		{
			ft_reverse_rotate_stack(b);
			ft_putstr_fd("rrb\n", 1);
		}
		else if ((*b)->index == max_index)
		{
			ft_pa(b, a);
			stack_size--;
		}
	}
}

void	ft_butterfly_sort(t_stack **a, t_stack **b, int koll_arg)
{
	int	i;
	int	point;

	point = ft_index_points(koll_arg);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			ft_pb(a, b);
			ft_rotate_stack(b);
			ft_putstr_fd("rb\n", 1);
			i++;
		}
		else if ((*a)->index <= (i + point))
		{
			ft_pb(a, b);
			i++;
		}
		else if ((*a)->index > i)
			ft_ra(a);
	}
	ft_push_back(a, b, koll_arg);
}
