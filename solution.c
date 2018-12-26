/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:14:19 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/26 17:14:48 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

void	put_figure(int size, unsigned char tab[size][size], t_tetra *tetra,
	   	int i, int j)
{
	int	h;
	int w;
	int a;
	int b;

	h = 0;
	a = i;
	while (h <= (tetra->p[1] - tetra->p[0]))
	{
		w = 0;
		b = j;
		while (w <= (tetra->p[3] - tetra->p[2]))
		{
			if (tetra->figure[h][w] == tetra->symb)
				tab[a][b] = tab[a][b] + tetra->symb;
			w++;
			b++;
		}
		h++;
		a++;
	}
}

int		check_figure(int size, unsigned char tab[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] > 'Z')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	remove_figure(int size, unsigned char tab[size][size], t_tetra *tetra, int i, int j)
{
	int h;
	int w;
	int a;
	int b;

	h = 0;
	a = i;
	while (h <= (tetra->p[1] - tetra->p[0]))
	{
		w = 0;
		b = j;
		while (w <= (tetra->p[3] - tetra->p[2]))
		{
			if (tab[a][b] > 'Z')
				tab[a][b] = tab[a][b] - tetra->symb;
			if (tab[a][b] == tetra->symb)
				tab[a][b] = 0;
			w++;
			b++;
		}
		h++;
		a++;
	}
}

void	print_map(int size, unsigned char tab[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] >= 'A' && tab[i][j] <= 'Z')
				ft_putchar(tab[i][j]);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void	cpy_arr(int size, unsigned char tab[size][size], unsigned char cpy[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			cpy[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
}

void zero_map(int size, unsigned char tab[size][size])
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		rec(int size, unsigned char tab[size][size], t_tetra *tetra, int *flag)
{
	int i;
	int j;
	unsigned char cpy[size][size];

	i = 0;
	while (i < (size - (tetra->p[1] - tetra->p[0])))
	{
		j = 0;
		while (j < (size - (tetra->p[3] - tetra->p[2])))
		{
			if (*flag == 1)
				return (1);
			if (i == 0 && j == 0 && tetra->symb == 'A')
				zero_map(size, tab);
			put_figure(size, tab, tetra, i, j);
			if (check_figure(size, tab) && !(tetra->next))
			{
				print_map(size,tab);
				*flag = 1;
				return (1);
			}
			if (!check_figure(size, tab))
				remove_figure(size, tab, tetra, i, j);
			else if (check_figure(size, tab) && tetra->next)
			{
				cpy_arr(size, tab, cpy);
				if (!(rec(size, cpy, tetra->next, flag)))
				{
					remove_figure(size,tab, tetra, i, j);
				}
			}
			j++;
		}
		i++;
	}
	if (tetra->symb == 'A')
		rec(size + 1, tab, tetra, flag);
	return (0);
}

int solut(t_tetra *tetra)
{
	int size = 2;
	unsigned char s[size][size];
	int i;
	int j;
	int flag;
	int *f;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			s[i][j] = 0;
			j++;
		}
		i++;
	}
	flag = 0;
	f = &flag;
	i = rec(size, s, tetra, f);
	return (1);
}
