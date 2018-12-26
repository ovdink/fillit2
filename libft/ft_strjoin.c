/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:59:46 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/26 17:17:39 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len1;
	int		len2;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	dst = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len1)
		dst[i] = s1[i];
	while (j < len2)
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}
