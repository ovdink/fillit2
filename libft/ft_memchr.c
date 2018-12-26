/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:03:21 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/29 15:37:11 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*t;

	i = 0;
	t = (char*)s;
	while (i < n)
	{
		if (t[i] == (char)c)
			return (t + i);
		i++;
	}
	return (NULL);
}
