/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:48:53 by nivergne          #+#    #+#             */
/*   Updated: 2019/06/05 02:46:44 by nivergne         ###   ########.fr       */
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
	int i = 0;
	p->piece_y = 0;
	while (p->piece_y < m->piece_height)
	{
		p->piece_x = 0;
		while (p->piece_x < m->piece_width)
		{
			if (m->piece[p->piece_y][p->piece_x] == '*')
			{
				p->distance = 1;
				while (p->distance <= p->best_distance)
				{
					i++;
					printf ("%d\n", i);
					if (get_dist_two(m, p) != 0 && p->distance < p->best_distance)
					{
						p->best_distance = p->distance;
						p->map_fin_x = p->map_x;
						p->map_fin_y = p->map_y;
					}
					p->distance++;
				}
			}
			p->piece_x++;
		}
		p->piece_y++;
	}
	return (1);
}