/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:33:21 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 18:33:23 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/** Stack functions */
void	ft_stack_push_value(t_stack **head, int value);
void	ft_stack_push_node(t_stack **head, t_stack **popped);
void	ft_stack_free(t_stack **head);
int		ft_get_stack_size(t_stack *head);

/** rules on stack*/
void	ft_swap_on_stack(t_stack **head);
void	ft_rotate_stack(t_stack **head);
void	ft_reverse_rotate_stack(t_stack **head);

/** Check arg */
int		pars_argv(char **argv);
int		ft_isduplicate_argv(char **mass);
int		size_mass(char **mass);

/** Commands */
void	ft_sa(t_stack **obj);
void	ft_rra(t_stack **obj);
void	ft_ra(t_stack **obj);
void	ft_pb(t_stack **src, t_stack **dst);
void	ft_pa(t_stack **src, t_stack **dst);

/** Validation functions*/
int		ft_check_if_stack_sorted(t_stack *head);
int		ft_check_index_stack_sorted(t_stack *head);
void	ft_free_mass(char **mass);
void	ft_print_three(t_stack **obj);
void	ft_print_five(t_stack **a, t_stack **b);

/** Utilities */
int		ft_atoi_my(const char *str);
void	ft_print_error(void);
int		ft_have_digits(char *str);
int		ft_argv_isnull(int argc, char **argv);
int		ft_find_max_index(t_stack *head);

/** Sorting functions */
void	ft_index_stack(t_stack *head);
int		ft_find_min_index(t_stack *obj);
void	ft_butterfly_sort(t_stack **a, t_stack **b, int koll_arg);
int		ft_check_mediana(t_stack **head, int ind, int argc);
void	ft_push_back(t_stack **a, t_stack **b, int argc);

/** main */
int		ft_nbrlen(long long nbr);
int		is_int(char *s);
int		push_mass_stack(int argc, char **argv, t_stack **a);
void	ft_check_argv(int argc, char **argv);
void	check_sort(t_stack **a, t_stack **b, int koll_argv);

/** checker */
int		push_mass_stack(int argc, char **argv, t_stack **a);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_checker_sort(t_stack *a, t_stack *b);
void	ft_commands(char *str, t_stack **a, t_stack **b);
int		get_next_line(char **line);
void	ft_you_can_do_it(void);

#endif
