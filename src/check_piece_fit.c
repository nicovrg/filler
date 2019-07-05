/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece_fit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 02:53:31 by nivergne          #+#    #+#             */
/*   Updated: 2019/07/05 07:51:31 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int		check_inmap(int x, int y, t_info *m, t_play *p)
{
	if (!(y >= 0 && x >= 0 && y < m->map_height && x < m->map_width))
		return (0);
	if (!(p->piece_y >= 0 && p->piece_x >= 0))
		return (0);
	if (!(p->piece_y < m->piece_height && p->piece_x < m->piece_width))
		return (0);
	return (1);
}

int		check_ally(t_info *m, t_play *p)
{
	int	x;
	int	y;

	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	if (check_inmap(x, y, m, p))
	{
		if (m->map[y][x] == m->p_id && m->piece[p->piece_y][p->piece_x] == '*')
		{
			if (p->link == 0)
			{
				p->link++;
				return (1);
			}
			return (0);
		}
	}
	return (1);
}

int		check_enemy(t_info *m, t_play *p)
{
	int	x;
	int y;

	x = p->map_x + p->piece_x;
	y = p->map_y + p->piece_y;
	if (y >= 0 && x >= 0 && y < m->map_height && x < m->map_width)
	{
		if (m->map[y][x] == m->e_id && m->piece[p->piece_y][p->piece_x] == '*')
			return (1);
	}
	return (0);
}

int		check_limit(t_info *m, t_play *p)
{
	if (p->map_y + p->piece_y < 0)
		return (0);
	if (p->map_x + p->piece_x < 0)
		return (0);
	if (p->map_y + p->piece_y >= m->map_height)
		return (0);
	if (p->map_x + p->piece_x >= m->map_width)
		return (0);
	return (1);
}

int		check_place(t_info *m, t_play *p)
{
	p->link = 0;
	p->piece_y = 0;
	while (p->piece_y < m->piece_height)
	{
		p->piece_x = 0;
		while (p->piece_x < m->piece_width)
		{
			if (!check_limit(m, p) && m->piece[p->piece_y][p->piece_x] == '*')
				return (0);
			else if (!check_ally(m, p))
				return (0);
			else if (check_enemy(m, p) == 1)
				return (0);
			p->piece_x++;
		}
		p->piece_y++;
	}
	return (p->link);
}
