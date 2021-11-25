/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:49:00 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:49:01 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	ft_isduplicate_argv(char **mass)
{
	int	i;
	int	j;

	i = -1;
	while (mass[++i])
	{
		j = i;
		while (mass[++j])
		{
			if ((ft_strncmp(mass[i], mass[j], ft_strlen(mass[j]))) == 0
				&& ft_strlen(mass[i]) == ft_strlen(mass[j]))
				return (1);
		}
	}
	return (0);
}

int	ft_have_digits(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	ft_argv_isnull(int argc, char **argv)
{
	while (argc-- > 1)
	{
		if (ft_strlen(argv[argc]) == 0)
			return (1);
		if (ft_have_digits(argv[argc]) == 0)
			return (1);
	}
	return (0);
}
