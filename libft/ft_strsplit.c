/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:32:09 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/30 12:03:54 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			j++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (j);
}

static int	ft_wordlen(char *str, char c)
{
	int i;

	i = 0;
	while ((str[i]) != c && str[i] != '\0')
		i++;
	return (i);
}

static void	fri(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static char	**tabz(char **tab, char *str, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (j < ft_count_words(str, c))
	{
		while (str[i] == c)
			i++;
		tab[j] = (char*)malloc(sizeof(char) * ft_wordlen(&str[i], c) + 1);
		if (!tab[j])
			fri(tab, j);
		k = 0;
		while (str[i] != c && str[i] != '\0')
			tab[j][k++] = str[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	char	*str;

	if (!s || !c)
		return (NULL);
	str = (char*)s;
	tab = (char**)malloc(sizeof(char*) * ft_count_words(str, c) + 1);
	if (!tab)
		return (NULL);
	j = 0;
	i = 0;
	tabz(tab, str, c);
	return (tab);
}
