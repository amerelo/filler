/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 23:58:15 by amerelo           #+#    #+#             */
/*   Updated: 2016/06/03 01:12:03 by amerelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "stdio.h"

typedef struct	s_box
{
	int			player;
	int 		x_map;
	int 		y_map;
	int 		x_part;
	int 		y_part;
	int			board;
	int			part;
	int			edx;
	int			edy;
	char		**map;
	char		**piece;
}				t_box;

void	place(t_box *box, int *x, int *y);
void	free_tab(char **tab);
void	init_box(t_box *box);
int		find_player_n(char *line, t_box *box);
int		get_part_size(char *line, t_box *box);
int		test_if_coor(char *line, t_box *box);
void	init_box(t_box *box);
void	free_tab(char **tab);
int		get_part(char *line, t_box *box, int *x);
int		place_ok(t_box *b, int y, int x, char player);

#endif
