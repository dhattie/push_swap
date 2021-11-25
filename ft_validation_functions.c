/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:52:09 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:52:11 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_index_stack_sorted(t_stack *head)
{
	if ((ft_get_stack_size(head) <= 1))
		return (0);
	else
	{
		while (head->next && head->index == head->next->index - 1)
			head = head->next;
		if (head->next == NULL)
			return (0);
	}
	return (1);
}
