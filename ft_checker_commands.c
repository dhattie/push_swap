/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:31:39 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/25 17:31:41 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	if (a && b)
	{
		ft_swap_on_stack(a);
		ft_swap_on_stack(b);
	}
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (a && b)
	{
		ft_rra(a);
		ft_rra(b);
	}
}

void	ft_you_can_do_it(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
