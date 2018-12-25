/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:43:27 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/25 16:36:59 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_sharp(char **tetra, char c)
{
	int w;
	int h;
	int contact;

	h = 0;
	contact = 0;
	while (h < 4)
	{
		w = 0;
		while (w < 4)
		{
			if (tetra[h][w] == c)
			{
				if (w < 3 && tetra[h][w + 1] == c)
					contact++;
				if (w > 0 && tetra[h][w - 1] == c)
					contact++;
				if (h > 0 && tetra[h - 1][w] == c)
					contact++;
				if (h < 3 && tetra[h + 1][w] == c)
					contact++;
			}
			w++;
		}
		h++;
	}
	if (contact == 6 || contact == 8)
		return(1);
	return (0);
}

int			check_map(char *s, int *flag)
{
	int i;
	int j;

	if (!s)
		return (0);
	if (ft_strlen(s) < 20)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (((i + 1) % 5 == 0) && s[i] != '\n')
			return (0);
		if (((i + 1) % 5 != 0) && (!(s[i] != '.' || s[i] != '#')))
			return (0);
		if (s[i] == '#')
			j++;
		i++;
	}
	if (!(s[20] == '\n' || s[20] == '\0') || j != 4)
		return (0);
	if (s[20] == '\0')
		*flag = 0;
	return (1);
}
