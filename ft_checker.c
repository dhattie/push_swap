/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:05:43 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/25 17:05:45 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(char **line)
{
	int	res;
	int	i;
	int	ch;

	res = 1;
	i = 0;
	ch = 0;
	*line = (char *)(malloc(sizeof (char) * 4));
	while (res > 0 && ch != '\n')
	{
		res = read(0, &ch, 1);
		if (ch != '\n')
			line[0][i++] = ch;
	}
	line[0][i] = '\0';
	return (res);
}

static void	ft_read_line(t_stack **a, t_stack **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		ft_commands(line, a, b);
		free(line);
		line = NULL;
	}
	free(line);
	line = NULL;
}

void	ft_checker_sort(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	if (b)
	{
		write(1, "KO\n", 3);
		exit(EXIT_FAILURE);
	}
	while (a->next)
	{
		if (a->value > a->next->value)
		{
			write(1, "KO\n", 3);
			exit(EXIT_FAILURE);
		}
		a = a->next;
	}
	write(1, "OK\n", 3);
	exit(EXIT_SUCCESS);
}

void	ft_commands(char *str, t_stack **a, t_stack **b)
{
	if (!(ft_strncmp(str, "sa", 3)))
		ft_swap_on_stack(a);
	else if (!(ft_strncmp(str, "sb", 3)))
		ft_swap_on_stack(b);
	else if (!(ft_strncmp(str, "ss", 3)))
		ft_ss(a, b);
	else if (!(ft_strncmp(str, "pa", 3)))
		ft_stack_push_node(b, a);
	else if (!(ft_strncmp(str, "pb", 3)))
		ft_stack_push_node(a, b);
	else if (!(ft_strncmp(str, "ra", 3)))
		ft_rotate_stack(a);
	else if (!(ft_strncmp(str, "rb", 3)))
		ft_rotate_stack(b);
	else if (!(ft_strncmp(str, "rr", 3)))
		ft_ss(a, b);
	else if (!(ft_strncmp(str, "rra", 3)))
		ft_reverse_rotate_stack(a);
	else if (!(ft_strncmp(str, "rrb", 3)))
		ft_reverse_rotate_stack(b);
	else if (!(ft_strncmp(str, "rrr", 3)))
		ft_rrr(a, b);
	else if (str[0])
		ft_you_can_do_it();
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	if (argc == 1)
		return (0);
	else
		push_mass_stack(argc, argv, &a);
	ft_read_line(&a, &b);
	ft_checker_sort(a, b);
	return (0);
}
