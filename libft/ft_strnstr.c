/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:10:27 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/26 17:15:08 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int str_i;
	int j;
	int k;

	k = 0;
	str_i = 0;
	while (((char*)needle)[k] != '\0')
		k++;
	if (((char*)needle)[0] == '\0')
		return ((char *)haystack);
	while (((char*)haystack)[str_i] != '\0' && str_i < ((int)(len - k + 1)))
	{
		j = 0;
		if (((char*)haystack)[str_i] == ((char*)needle)[j])
		{
			while (((char*)needle)[j] == ((char*)haystack)[str_i + j])
			{
				if (((char*)needle)[j + 1] == '\0')
					return (((char*)haystack) + str_i);
				j++;
			}
		}
		str_i++;
	}
	return (NULL);
}
