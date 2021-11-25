/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:49:52 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:49:54 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push_value(t_stack **head, int value)
{
	t_stack	*tmp;

	if (head)
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			exit(1);
		tmp->value = value;
		tmp->index = -1;
		tmp->next = *head;
		*head = tmp;
	}
}

void	ft_stack_push_node(t_stack **head, t_stack **destination)
{
	t_stack	*node;

	node = *head;
	*head = (*head)->next;
	node->next = NULL;
	if (!(*destination))
		*destination = node;
	else
	{
		node->next = *destination;
		*destination = node;
	}
}
