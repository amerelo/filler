/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerelo <amerelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 23:58:15 by amerelo           #+#    #+#             */
/*   Updated: 2016/05/30 16:55:21 by amerelo          ###   ########.fr       */
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
	char		**map;
	char		**piece;
}				t_box;

#endif
