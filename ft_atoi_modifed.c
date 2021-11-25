/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 09:47:32 by dhattie           #+#    #+#             */
/*   Updated: 2021/11/24 09:47:34 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*ft_skip_ch(const char *s)
{
	const char	*point;

	while (*s == ' ' || *s == '\n' || *s == '\t' || *s == '\f' || \
	*s == '\r' || *s == '\v')
		s++;
	point = s;
	return (point);
}

static int	ft_limit_int(long long n, const char *s, int sign)
{
	long long	min;
	long long	max;

	min = ((n * 10) + (*s - '0')) * sign;
	if (min < -2147483648)
		return (0);
	max = ((n * 10) + (*s - '0')) * sign;
	if (max > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi_my(const char *str)
{
	int			nbr;
	int			sign;
	const char	*t;
	int			check_limit;

	nbr = 0;
	sign = 1;
	t = ft_skip_ch(str);
	if (*t == '-')
		sign = -1;
	if (*t == '-' || *t == '+')
		t++;
	while (*t >= '0' && *t <= '9')
	{
		check_limit = ft_limit_int(nbr, t, sign);
		if (check_limit == 0 || check_limit == -1)
			return (check_limit);
		nbr = nbr * 10 + *t++ - '0';
	}
	return (nbr * sign);
}
