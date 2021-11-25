/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:51:30 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:51:32 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min_index(t_stack *obj)
{
	int	min;

	min = obj->index;
	while (obj)
	{
		if (min > obj->index)
			min = obj->index;
		obj = obj->next;
	}
	return (min);
}

void	ft_print_three(t_stack **obj)
{
	while (ft_check_index_stack_sorted(*obj))
	{
		if ((*obj)->index > (*obj)->next->index)
			ft_sa(obj);
		else if ((*obj)->index < (*obj)->next->index)
			ft_rra(obj);
	}
}

void static	ft_wtf(t_stack **a, t_stack **b, int *stack_size, int *i)
{
	ft_pb(a, b);
	*stack_size = *stack_size -1;
	*i = *i + 1;
}

void	ft_print_five(t_stack **a, t_stack **b)
{
	int	i;
	int	stack_size;
	int	min_index;
	int	check_mediana;

	i = 0;
	stack_size = ft_get_stack_size(*a);
	while (i < 3)
	{
		min_index = ft_find_min_index(*a);
		check_mediana = ft_check_mediana(a, min_index, stack_size);
		if ((*a)->index > min_index && !check_mediana)
			ft_ra(a);
		else if ((*a)->index > min_index && check_mediana)
			ft_rra(a);
		else
			ft_wtf(a, b, &stack_size, &i);
	}
	if ((*a)->index != ft_find_min_index(*a))
		ft_sa(a);
	while (*b)
		ft_pa(b, a);
}
