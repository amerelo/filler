/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 21:02:01 by amerelo           #+#    #+#             */
/*   Updated: 2016/05/30 16:58:49 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_box(t_box *box)
{
	box->player = 0;
	box->x_map = 0;
	box->y_map = 0;
	box->board = 0;
	box->part = 0;
	box->map = NULL;
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

int		find_player_n(char *line, t_box *box)
{
	char **name;

	name = ft_strsplit(line, ' ');
	if (!ft_strequ(name[0], "$$$") || !ft_strequ(name[1], "exec"))
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
		box->player	 = 2;
		free_tab(name);
		return (1);
	}
	free_tab(name);
	return (0);
}

int		test_if_coor(char *line, t_box *box)
{
	char	**tmp;
	tmp = ft_strsplit(line, ' ');
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

int		get_map(char *line, t_box *box)
{
	static int	x = 0;
	char		*tmp;

	if (!(tmp = ft_strchr(line, ' ')) && (int)ft_strlen(++tmp) != box->y_map)
		return (0);
	++tmp;
	box->map[x] = (char*)ft_memalloc(sizeof(char) * (box->x_map + 1));
	box->map[x] = ft_strdup(tmp);
	++x;
	if (x == box->y_map)
		++box->board;
	return (1);
}

int		find_map(char *line, t_box *box)
{
	if (box->player && box->board == 0 && test_if_coor(line, box))
		return (1);
	else if (box->player && box->board == 1)
	{
		++box->board;
		return (1);
	}
	else if (box->player && box->board == 2 && get_map(line, box))
		return (1);
	return (0);
}

int		find_map(char *line, t_box *box)
{
	if (box->player && box->board == 0 && test_if_coor(line, box))
		return (1);
	else if (box->player && box->board == 1)
	{
		++box->board;
		return (1);
	}
	else if (box->player && box->board == 2 && get_map(line, box))
		return (1);
	return (0);
}

void	print_tab(t_box *box)//
{
	int x;
	int y;

	y = 0;
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			printf("%c", box->map[y][x]);
			++x;
		}
		++y;
		printf("\n");
	}
}

int		get_info(t_box *box)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (!box->player && find_player_n(line, box))
			free(line);
		else if (box->board < 3 && find_map(line, box))
			free(line);
		else if (find_part(line, box))
		{
			free(line);
			if (box->part == 1)
				return (1);
		}
		else
		{
			free(line);
			return (0);
		}
	}
	print_tab(box);
	return (1);
}

int		main(void)
{
	t_box box;

	init_box(&box);
	if (!get_info(&box))
		return (1); // error function
	return (0);
}
