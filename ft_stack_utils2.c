/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:10 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 15:44:12 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_mass(char **mass)
{
	int	i;

	i = -1;
	while (mass[++i])
	{
		free(mass[i]);
		mass[i] = NULL;
	}
	free(mass);
	mass = NULL;
}

static void	index_to_mas(t_stack *head, int *mas)
{
	int	i;

	i = 0;
	while (head)
	{
		mas[i] = head->index;
		head = head->next;
		i++;
	}
}

int	ft_check_mediana(t_stack **head, int ind, int stack_size)
{
	int		*mas;
	int		i;
	int		stap_1;
	int		stap_2;

	stap_1 = 0;
	stap_2 = 0;
	i = 0;
	mas = (int *)malloc(sizeof(int) * (stack_size + 1));
	if (!mas)
		ft_print_error();
	index_to_mas(*head, mas);
	stack_size--;
	while (mas[stack_size--] != ind)
		stap_1++;
	while (mas[i++] != ind)
		stap_2++;
	free(mas);
	if (stap_2 > stap_1)
		return (1);
	return (0);
}

void	ft_check_argv(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	if (argc > 1 && ft_argv_isnull(argc, argv))
		ft_print_error();
}

void	check_sort(t_stack **a, t_stack **b, int koll_argv)
{
	if (ft_get_stack_size(*a) <= 3)
		ft_print_three(a);
	else if (ft_get_stack_size(*a) <= 5)
		ft_print_five(a, b);
	else if (ft_get_stack_size(*a) > 5)
		ft_butterfly_sort(a, b, koll_argv);
	ft_stack_free(a);
	ft_stack_free(b);
}
