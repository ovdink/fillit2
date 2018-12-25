/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:21:40 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/25 16:22:55 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change_figure(t_tetra **tetra)
{
	char **tab;
	int i;
	int j;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * ((*tetra)->p[1] - (*tetra)->p[0] + 1));
	while (i < ((*tetra)->p[1] - (*tetra)->p[0] + 1))
	{
		tab[i] = (char*)malloc(sizeof(char) * ((*tetra)->p[3] - (*tetra)->p[2] + 1));
		j = 0;
		while (j < ((*tetra)->p[3] - (*tetra)->p[2] + 1))
		{
			tab[i][j] = (*tetra)->figure[i + (*tetra)->p[0]][j + (*tetra)->p[2]];
			j++;
		}
		i++;
	}
	free((*tetra)->figure);
	(*tetra)->figure = tab;
}

void	points(t_tetra **tetra)
{
	int i;
	int j;

	i = -1;
	(*tetra)->p[0] = 3;
	(*tetra)->p[1] = 0;
	(*tetra)->p[2] = 3;
	(*tetra)->p[3] = 0;
	while (i++ < 3)
	{
		j = -1;
		while (j++ < 3)
			if ((*tetra)->figure[i][j] == (*tetra)->symb)
			{
				if (i < (*tetra)->p[0])
 					(*tetra)->p[0] = i;
				if (i > (*tetra)->p[1])
 					(*tetra)->p[1] = i;
				if (j < (*tetra)->p[2])
 					(*tetra)->p[2] = j;
				if (j > (*tetra)->p[3])
 					(*tetra)->p[3] = j;
			}
	}
	change_figure(tetra);
}

void		print_figures(t_tetra *lst)
{
	int i;
	int j;

	while (lst)
	{
		i = 0;
		while (i < (lst->p[1] - lst->p[0] + 1))
		{
			j = 0;
			while (j < (lst->p[3] - lst->p[2] + 1))
			{
				printf("%c", lst->figure[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
		printf("\n");
		i = 0;
		/*while (i < 4)
		{
			printf("%d ", lst->p[i]);
			i++;
		}
		printf("\n");*/
		lst = lst->next;
	}
}

int		get_figure(char *s, t_tetra **tetra)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	(*tetra)->figure = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		(*tetra)->figure[i] = (char*)malloc(sizeof(char) * 4);
		j = 0;
		while (j < 4)
		{
			if (s[k] == '#')
				(*tetra)->figure[i][j] = (*tetra)->symb;
			else
				(*tetra)->figure[i][j] = s[k];
			j++;
			k++;
		}
		k++;
		i++;
	}
	if (!(check_sharp((*tetra)->figure, (*tetra)->symb)))
		return (0);
	points(tetra);
	return (1);
}

int			add_node(t_tetra **lst, char *s)
{
	t_tetra		*new_tetra;
	t_tetra		*to_end;
	static int	i;

	new_tetra = (t_tetra*)malloc(sizeof(t_tetra));
	new_tetra->symb = 'A' + (i++);
	if(!(get_figure(s, &new_tetra)))
		return (0);
	new_tetra->next = NULL;
	if (!(*lst))
	{
		*lst = new_tetra;
		return (1);
	}
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new_tetra;
		return (1);
	}
	to_end = *lst;
	while (to_end->next)
		to_end = to_end->next;
	to_end->next = new_tetra;
	if (new_tetra->symb > 'Z')
		return (0);
	return (1);
}
