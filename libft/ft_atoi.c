/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:06:34 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/02 15:45:42 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long int	ato;
	long int	plmi;
	int			check;

	ato = 0;
	plmi = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
	|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		plmi = -1;
	if (*str == '-' || *str == '+')
		str++;
	check = ato;
	while (*str >= '0' && *str <= '9')
	{
		ato = ato * 10 + plmi * (*str - '0');
		if (ato < check && plmi == 1)
			return (-1);
		if (ato > check && plmi == -1)
			return (0);
		check = ato;
		str++;
	}
	return (ato);
}
