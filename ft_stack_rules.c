/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:49:24 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:49:26 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_on_stack(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if ((*head)->next)
	{
		first = *head;
		second = (*head)->next;
		third = (*head)->next->next;
		first->next = third;
		second->next = first;
		*head = second;
	}
}

void	ft_rotate_stack(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*copy;

	if ((*head) && (*head)->next)
	{
		copy = *head;
		first = *head;
		second = (*head)->next;
		while (copy->next)
			copy = copy->next;
		first->next = NULL;
		*head = second;
		copy->next = first;
	}
}

void	ft_reverse_rotate_stack(t_stack **head)
{
	t_stack		*first;
	t_stack		*penult;

	if ((*head) && (*head)->next)
	{
		penult = *head;
		first = (*head);
		while (penult->next->next)
			penult = penult->next;
		(*head) = penult->next;
		penult->next = NULL;
		(*head)->next = first;
	}
}
