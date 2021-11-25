/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:50:17 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:50:19 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_stack_size(t_stack *head)
{
	int	size;

	size = 0;
	while (head)
	{
		head = head->next;
		size += 1;
	}
	return (size);
}

void	ft_stack_free(t_stack **head)
{
	t_stack	*tmp;

	if (*head)
	{
		while (*head)
		{
			tmp = (*head)->next;
			free(*head);
			*head = NULL;
			*head = tmp;
		}
	}
}

void	ft_index_stack(t_stack *head)
{
	int			index;
	t_stack		*min;
	t_stack		*len;
	t_stack		*tmp;

	len = head;
	index = 0;
	while (len)
	{
		min = head;
		while (min->index >= 0)
			min = min->next;
		tmp = head;
		while (tmp)
		{
			if (min->value > tmp->value && tmp->index == -1)
				min = tmp;
			tmp = tmp->next;
		}
		min->index = index++;
		len = len->next;
	}
}

int	ft_find_max_index(t_stack *head)
{
	t_stack	*tmp;
	int		i;

	tmp = head;
	i = tmp->index;
	while (tmp)
	{
		if (i < tmp->index)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

int	size_mass(char **mass)
{
	int	size_mass;

	size_mass = 0;
	while (mass[size_mass])
		size_mass++;
	return (size_mass);
}
