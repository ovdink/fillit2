/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:46:03 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/29 15:36:33 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*area;
	size_t		i;

	area = malloc(size);
	if (!area)
		return (0);
	i = 0;
	while (i < size)
	{
		((unsigned char*)area)[i] = 0;
		i++;
	}
	return (area);
}
