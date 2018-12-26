/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:00:57 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/30 11:57:46 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;
	int		len;

	if (s && f)
	{
		len = 0;
		while (s[len] != '\0')
			len++;
		dst = malloc(sizeof(char) * len + 1);
		if (!dst)
			return (NULL);
		i = 0;
		while (i < len)
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
