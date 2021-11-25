/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:52:41 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:52:43 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			koll_arg;

	ft_check_argv(argc, argv);
	koll_arg = push_mass_stack(argc, argv, &a);
	ft_index_stack(a);
	if ((ft_check_index_stack_sorted(a) == 0))
		exit(0);
	else
		check_sort(&a, &b, koll_arg);
	return (0);
}
