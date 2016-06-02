/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 01:04:44 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/03 01:13:38 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_player_n(char *line, t_box *box)
{
	char **name;

	name = ft_strsplit(line, ' ');
	if (!ft_strequ(name[0], "$$$") || !ft_strequ(name[1], "exec") ||
	!ft_strstr(name[4], "filler"))
	{
		free_tab(name);
		return (0);
	}
	if (ft_strequ(name[2], "p1"))
	{
		box->player = 1;
		free_tab(name);
		return (1);
	}
	if (ft_strequ(name[2], "p2"))
	{
		box->player = 2;
		free_tab(name);
		return (1);
	}
	free_tab(name);
	return (0);
}

int		get_part_size(char *line, t_box *box)
{
	char	**tmp;

	printf("%s\n", "");
	tmp = ft_strsplit(line, ' ');
	if (!ft_strequ(tmp[0], "Piece") && !tmp[1] && !tmp[2])
	{
		free_tab(tmp);
		return (0);
	}
	box->y_part = ft_atoi(tmp[1]);
	box->x_part = ft_atoi(tmp[2]);
	box->piece = (char**)ft_memalloc(sizeof(char*) * (box->y_part + 1));
	box->part = 1;
	free_tab(tmp);
	return (1);
}

int		test_if_coor(char *line, t_box *box)
{
	char	**tmp;

	if (!(tmp = ft_strsplit(line, ' ')) && !tmp[0])
		return (0);
	if (!tmp[0])
	{
		printf("%s\n", "no");
		return (0);
	}
	if (!ft_strequ(tmp[0], "Plateau") && !tmp[1] && !tmp[2])
	{
		free_tab(tmp);
		return (0);
	}
	box->y_map = ft_atoi(tmp[1]);
	box->x_map = ft_atoi(tmp[2]);
	box->map = (char**)ft_memalloc(sizeof(char*) * (box->y_map + 1));
	++box->board;
	free_tab(tmp);
	return (1);
}

void	init_box(t_box *box)
{
	box->player = 0;
	box->x_map = 0;
	box->y_map = 0;
	box->x_part = 0;
	box->y_part = 0;
	box->board = 0;
	box->part = 0;
	box->edx = 0;
	box->edy = 0;
	box->map = NULL;
	box->piece = NULL;
}

void	free_tab(char **tab)
{
	int x;

	x = 0;
	while (tab[x] && tab[x][0])
	{
		free(tab[x]);
		++x;
	}
	free(tab);
}
