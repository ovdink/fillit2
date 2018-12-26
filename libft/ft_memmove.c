/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:22:46 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/29 14:18:11 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	char		*s;
	int			i;

	d = (char *)dst;
	s = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (!len)
		return (dst);
	i = (int)len;
	if (src < dst)
		while ((--i) >= 0)
			*(d + i) = *(s + i);
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	return (dst);
}
