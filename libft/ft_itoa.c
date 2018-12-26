/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:34:45 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/29 15:45:26 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int i;

	i = 0;
	while (n > 9 || n < -9)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	char	*s;
	int		notn;
	int		check;

	check = 1;
	i = 0;
	notn = n;
	i = ft_len(n);
	if (n < 0)
		check = -1;
	s = (char*)malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	s[i + 1] = '\0';
	s[i--] = (notn % 10) * check + '0';
	while (notn /= 10)
		s[i--] = (check * notn % 10 + '0');
	if (n < 0)
		s[0] = '-';
	return (s);
}
