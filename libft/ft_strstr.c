/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:31:38 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/28 13:16:28 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int str_i;
	int j;

	str_i = 0;
	if (((char*)needle)[0] == '\0')
		return ((char *)haystack);
	while (((char*)haystack)[str_i] != '\0')
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
