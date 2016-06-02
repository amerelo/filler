/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 16:38:24 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/03 01:12:09 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		free_space(t_box *box, int x, int y)
{
	int count;

	count = 0;
	if ((x - 2) >= 0 && box->map[y][x - 1] == '.' && box->map[y][x - 2] == '.')
		++count;
	if ((x + 2) < box->x_map && box->map[y][x + 1] == '.' &&
		box->map[y][x + 2] == '.')
		++count;
	if ((y - 2) >= 0 && box->map[y - 1][x] == '.' && box->map[y - 2][x] == '.')
		++count;
	if ((y + 2) < box->y_map && box->map[y + 1][x] == '.' &&
		box->map[y + 2][x] == '.')
		++count;
	if (count >= 2)
		return (1);
	return (0);
}

int		dis(t_box *box)
{
	int		x;
	int		y;
	char	player;

	y = 0;
	player = (box->player == 1) ? 'X' : 'O';
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (box->map[y][x] == player && free_space(box, x, y))
			{
				box->edx = x;
				box->edy = y;
				return (1);
			}
			++x;
		}
		++y;
	}
	return (0);
}

int		distance_between(int xa, int ya, int xb, int yb)
{
	int d1;
	int d2;

	d1 = xb - xa;
	d2 = yb - ya;
	d1 = d1 * d1;
	d2 = d2 * d2;
	d1 = d1 + d2;
	return (d1);
}

void	find_where_palce(t_box *box, int *t1, int *t2)
{
	int		x;
	int		y;
	char	player;

	y = 0;
	player = (box->player == 1) ? 'O' : 'X';
	while (box->map[y])
	{
		x = 0;
		while (box->map[y][x])
		{
			if (place_ok(box, y, x, player))
			{
				if (((*t1) == -1 && (*t2) == -1) || (dis(box) &&
				distance_between((*t2), (*t1), box->edx, box->edy) >
				distance_between(x, y, box->edx, box->edy)))
				{
					(*t1) = y;
					(*t2) = x;
				}
			}
			++x;
		}
		++y;
	}
}

void	place(t_box *box, int *x, int *y)
{
	int tmp;
	int t1;
	int t2;

	*x = 0;
	*y = 0;
	t1 = -1;
	t2 = -1;
	find_where_palce(box, &t1, &t2);
	ft_putnbr(t1);
	ft_putchar(' ');
	ft_putnbr(t2);
	ft_putchar('\n');
	free_tab(box->map);
	free_tab(box->piece);
	tmp = box->player;
	init_box(box);
	box->player = tmp;
}
