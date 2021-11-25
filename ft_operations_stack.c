/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:51:10 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:51:11 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **node)
{
	if (*node)
	{
		ft_swap_on_stack(node);
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_rra(t_stack **node)
{
	if (node)
	{
		ft_reverse_rotate_stack(node);
		ft_putstr_fd("rra\n", 1);
	}
}

void	ft_ra(t_stack **node)
{
	if (node)
	{
		ft_rotate_stack(node);
		ft_putstr_fd("ra\n", 1);
	}
}

void	ft_pb(t_stack **src, t_stack **dst)
{
	if (src)
	{
		ft_stack_push_node(src, dst);
		ft_putstr_fd("pb\n", 1);
	}
}

void	ft_pa(t_stack **src, t_stack **dst)
{
	if (src)
	{
		ft_stack_push_node(src, dst);
		ft_putstr_fd("pa\n", 1);
	}
}
