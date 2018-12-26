/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:14:13 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/28 13:00:52 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		len;
	int		k;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len] == '\0')
		len--;
	len++;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	((len - i) < 1) ? (dst = (char*)malloc(sizeof(char))) :
		(dst = (char*)malloc(sizeof(char) * (len - i) + 1));
	if (!dst)
		return (NULL);
	k = 0;
	while (i < len)
		dst[k++] = s[i++];
	dst[k] = '\0';
	return (dst);
}
