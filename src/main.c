/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 21:02:01 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/03 01:12:06 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_map(char *line, t_box *box, int *x)
{
	char	*tmp;

	if (!(tmp = ft_strchr(line, ' ')))
		return (0);
	if (!(tmp = ft_strchr(line, ' ')) && (int)ft_strlen(++tmp) != box->y_map)
		return (0);
	++tmp;
	box->map[*x] = (char*)ft_memalloc(sizeof(char) * (box->x_map + 1));
	box->map[*x] = ft_strdup(tmp);
	++(*x);
	if (*x == box->y_map)
		++box->board;
	return (1);
}

int		find_part(char *line, t_box *box, int *x)
{
	if (box->player && box->part == 0 && get_part_size(line, box))
		return (1);
	else if (box->player && box->part == 1 && get_part(line, box, x))
		return (1);
	return (0);
}

int		find_map(char *line, t_box *box, int *x)
{
	if (box->player && box->board == 0 && test_if_coor(line, box))
		return (1);
	else if (box->player && box->board == 1)
	{
		++box->board;
		return (1);
	}
	else if (box->player && box->board == 2 && get_map(line, box, x))
		return (1);
	return (0);
}

int		get_info(t_box *box)
{
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!box->player && find_player_n(line, box))
			free(line);
		else if (box->board < 3 && find_map(line, box, &x))
			free(line);
		else if (box->board == 3 && find_part(line, box, &y))
		{
			free(line);
			if (box->part == 2)
				place(box, &x, &y);
		}
		else
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

int		main(void)
{
	t_box box;

	init_box(&box);
	if (!get_info(&box))
		return (1);
	return (0);
}
