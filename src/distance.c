/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:48:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/21 02:56:14 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		get_dist_two(t_info *m, t_play *p)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = p->distance;
	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	while (j >= 0 && x < m->map_width && y < m->map_height)
	{
		if ((y + j < m->map_height && x + i < m->map_width && m->map[y + j][x + i] == m->opponent_id)
		|| ((y - j >= 0 && x + i < m->map_width && m->map[y - j][x + i] == m->opponent_id))
		|| ((y + j < m->map_height && x - i >= 0 && m->map[y + j][x - i] == m->opponent_id))
		|| ((y - j >= 0 && x - i >= 0 && m->map[y - j][x - i] == m->opponent_id)))
			return (j);
		i++;
		j--;
	}
	return (0);
}

int		get_dist_one(t_info *m, t_play *p)
{
	p->piece_y2 = 0;
	while (p->piece_y2 < m->piece_height)
	{
		p->piece_x2 = 0;
		while (p->piece_x2 < m->piece_width)
		{
			if (m->piece[p->piece_y2][p->piece_x2] == '*')
			{
				p->distance = 1;
				while (p->distance <= p->best_distance)
				{
					if (get_dist_two(m, p) != 0 && p->distance < p->best_distance)
					{
						p->best_distance = p->distance;
						p->map_fin_x = p->map_x;
						p->map_fin_y = p->map_y;
					}
					p->distance++;
				}
			}
			p->piece_x2++;
		}
		p->piece_y2++;
	}
	return (1);
}