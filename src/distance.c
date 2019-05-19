/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:48:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/05/19 22:31:59 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		get_dist_two(t_info *m, t_play *p)
{
	int i;
	int x;
	int y;
	int distance_tmp;

	i = 0;
	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	distance_tmp = p->distance;
	while (distance_tmp >= 0)
	{
		if ((y + distance_tmp < m->map_height && x + i < m->map_width && m->map[y + distance_tmp][x + i] == m->opponent_id)
		|| ((y - distance_tmp >= 0 && x + i < m->map_width && m->map[y - distance_tmp][x + i] == m->opponent_id))
		|| ((y + distance_tmp < m->map_height && x - i >= 0 && m->map[y + distance_tmp][x - i] == m->opponent_id))
		|| ((y - distance_tmp >= 0 && x - i >= 0 && m->map[y - distance_tmp][x - i] == m->opponent_id)))
			return (distance_tmp);
		i++;
		distance_tmp--;
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