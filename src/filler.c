/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:23:30 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/02 22:55:08 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		write_piece_position(int x, int y)
{
	ft_putnbr(y);
	write (1, " ", 1);
	ft_putnbr(x);
	write (1, "\n", 1);
	return (0);
}

int		map_iterate(t_info *m, t_play *p)
{
	p->map_y = -m->piece_first_y;
	while (p->map_y < m->map_height)
	{
		p->map_x = -m->piece_first_x;
		while (p->map_x < m->map_width)
		{
			if (check_place(m, p) == 1)
				get_distance(m, p);
			p->map_x++;
		}
		p->map_y++;
	}
	return (1);
}

int		play(t_info *m, t_play *p)
{	
	if (!map_iterate(m, p))
		return (ft_error("no place found for piece on map"));
	write_piece_position(p->map_fin_x, p->map_fin_y);
	if (p->map_fin_x == 0 && p->map_fin_y == 0)
		return (0);
	return (1);
}
