/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 01:10:03 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/03 01:12:05 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_part(char *line, t_box *box, int *x)
{
	if ((int)ft_strlen(line) != box->x_part)
		return (0);
	box->piece[*x] = (char*)ft_memalloc(sizeof(char) * (box->x_part + 1));
	box->piece[*x] = ft_strdup(line);
	++(*x);
	if (*x == box->y_part)
		++box->part;
	return (1);
}

int		place_ok(t_box *b, int y, int x, char player)
{
	int	count;
	int	x_p;
	int	y_p;

	y_p = 0;
	count = 0;
	if ((b->x_map - x - b->x_part) < 0 || (b->y_map - y - b->y_part) < 0)
		return (0);
	while (b->piece[y_p])
	{
		x_p = 0;
		while (b->piece[y_p][x_p])
		{
			if (b->map[y + y_p][x + x_p] == player && b->piece[y_p][x_p] == '*')
				++count;
			else if (b->map[y + y_p][x + x_p] != '.' &&
			b->piece[y_p][x_p] == '*')
				count = 2;
			++x_p;
		}
		++y_p;
	}
	if (count == 1)
		return (1);
	return (0);
}
