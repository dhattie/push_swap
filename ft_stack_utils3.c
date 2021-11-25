/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:31:17 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/25 19:31:19 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbrlen(long long nbr)
{
	int	nbrlen;

	nbrlen = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = nbr * (-1);
	while (nbr > 0)
	{
		nbrlen++;
		nbr = nbr / 10;
	}
	return (nbrlen);
}

int	is_int(char *s)
{
	int	nbrlen;

	nbrlen = ft_nbrlen(ft_atoi_my(s));
	if (*s == '-' || *s == '+')
		s++;
	if (nbrlen != ft_strlen(s))
		return (-1);
	return (1);
}

static void	ft_check_mass(char **mass)
{
	int			j;
	long int	num;

	num = 0;
	j = 0;
	if (!mass && !mass[0])
		ft_print_error();
	if (ft_isduplicate_argv(mass) == 1)
	{
		ft_free_mass(mass);
		ft_print_error();
	}
	while (mass[j])
	{
		num = ft_atoi_my(mass[j]);
		if (!(is_int(mass[j]) > 0))
		{
			ft_free_mass(mass);
			ft_print_error();
		}
		j++;
	}
}

static char	**ft_pars_argv(int argc, char **argv)
{
	char	**mass;
	char	*str;
	char	*mem;
	int		i;

	i = 1;
	str = calloc(1, 1);
	mem = NULL;
	while (i < argc)
	{
		mem = ft_strjoin(str, argv[i]);
		free(str);
		str = NULL;
		str = ft_strjoin(mem, " ");
		free(mem);
		mem = NULL;
		i++;
	}
	mass = ft_split(str, ' ');
	free(str);
	return (mass);
}

int	push_mass_stack(int argc, char **argv, t_stack **a)
{
	char		**mass;
	int			i;
	int			koll_arg;

	mass = ft_pars_argv(argc, argv);
	ft_check_mass(mass);
	i = size_mass(mass);
	koll_arg = i;
	while (--i >= 0)
		ft_stack_push_value(a, (int)ft_atoi_my(mass[i]));
	ft_free_mass(mass);
	return (koll_arg);
}
